/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/01 05:28:14 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int add_sphere(t_rt *rt,char *line)
{
	int			i;
	t_sphere	*new_sphere;

	new_sphere = init_sphere();
	i = 2;
	i = skip_spaces(line, i);
	if (check_is_a_vector(line, &i, &new_sphere->sp_center))
		return (print_error_arg(*rt, ERR_NOT_VECTOR, STR_SPHERE, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_float(line, &i, &new_sphere->sp_diam))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_SPHERE, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_rgb(line, &i, &new_sphere->sp_color))
		return (print_error_arg(*rt, ERR_RGB, STR_SPHERE, NO_FREE_MLX));
	if (!check_if_empty_str(&line[i]))
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_AMBIENT_LIGHT, NO_FREE_MLX));
	add_sphere_lst(rt, new_sphere);
	return (0);
}

int add_plane(t_rt *rt,char *line)
{
	(void) rt;
	(void) line;
	return (0);
}

int add_cylinder(t_rt *rt,char *line)
{
	(void) rt;
	(void) line;
	return (0);
}

void	add_sphere_lst(t_rt *rt, t_sphere *new_sphere)
{
	t_sphere	*lst_sphere;

	if (rt->scene.sp == NULL)
		rt->scene.sp = new_sphere;
	else
	{
		lst_sphere = rt->scene.sp;
		while (lst_sphere)
			lst_sphere = lst_sphere->next;
		lst_sphere->next = new_sphere;
	}
}
t_sphere	*init_sphere(void)
{
	t_sphere *new_sphere;

	new_sphere = (t_sphere *)malloc(sizeof(t_sphere));
	new_sphere->next = NULL;
	return (new_sphere);
}