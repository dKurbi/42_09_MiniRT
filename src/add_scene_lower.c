/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/06 04:00:38 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	add_sphere(t_rt *rt, char *line)
{
	int			i;
	t_sphere	*new_sphere;

	new_sphere = init_sphere();
	if (!new_sphere)
		return (print_error(*rt, ERR_MALLOC, NO_FREE_MLX));
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
	if (empty_after_line(line, i) == 0)
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_SPHERE, NO_FREE_MLX));
	add_sphere_lst(rt, new_sphere);
	return (0);
}

int	add_plane(t_rt *rt, char *line)
{
	int		i;
	t_plane	*new_plane;

	new_plane = init_plane();
	if (!new_plane)
		return (print_error(*rt, ERR_MALLOC, NO_FREE_MLX));
	i = 2;
	i = skip_spaces(line, i);
	if (check_is_a_vector(line, &i, &new_plane->pl_point))
		return (print_error_arg(*rt, ERR_NOT_VECTOR, STR_PLANE, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_vector_range(line, &i, &new_plane->pl_normal))
		return (print_error_arg(*rt, ERR_VECTOR_RANGE, STR_PLANE, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_rgb(line, &i, &new_plane->pl_color))
		return (print_error_arg(*rt, ERR_RGB, STR_PLANE, NO_FREE_MLX));
	if (empty_after_line(line, i) == 0)
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_PLANE, NO_FREE_MLX));
	add_plane_lst(rt, new_plane);
	return (0);
}

int	add_cylinder(t_rt *rt, char *line)
{
	int			i;
	t_cylinder	*new_cyl;

	new_cyl = init_cylinder();
	if (!new_cyl)
		return (print_error(*rt, ERR_MALLOC, NO_FREE_MLX));
	i = skip_spaces(line, 2);
	if (check_is_a_vector(line, &i, &new_cyl->cy_center))
		return (print_error_arg(*rt, ERR_NOT_VECTOR, STR_CYL, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_vector_range(line, &i, &new_cyl->cy_axis))
		return (print_error_arg(*rt, ERR_VECTOR_RANGE, STR_CYL, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_float(line, &i, &new_cyl->cy_diam))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_CYL, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_float(line, &i, &new_cyl->cy_height))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_CYL, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_rgb(line, &i, &new_cyl->cy_color))
		return (print_error_arg(*rt, ERR_RGB, STR_CYL, NO_FREE_MLX));
	if (empty_after_line(line, i) == 0)
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_CYL, NO_FREE_MLX));
	add_cylinder_lst(rt, new_cyl);
	return (0);
}
