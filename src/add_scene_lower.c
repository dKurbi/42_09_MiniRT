/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/08/17 19:50:28 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//check and add sp and its values
int	add_sphere(t_rt *rt, char *line)
{
	int			i;
	t_sphere	*new_sphere;

	new_sphere = init_sphere();
	if (!new_sphere)
		return (print_error(*rt, ERR_MALLOC, NO_FREE_MLX));
	i = 2;
	if (skip_space_check_not_enough_values(line, &i))
		return (free_sphere(&new_sphere), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_SPHERE, NO_FREE_MLX), 1);
	if (check_is_a_vector(line, &i, &new_sphere->sp_center))
		return (free_sphere(&new_sphere), \
			print_error_arg(*rt, ERR_NOT_VECTOR, STR_SPHERE, NO_FREE_MLX), 1);
	if (skip_space_check_not_enough_values(line, &i))
		return (free_sphere(&new_sphere), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_SPHERE, NO_FREE_MLX), 1);
	if (check_is_a_float(line, &i, &new_sphere->sp_diam))
		return (free_sphere(&new_sphere), \
			print_error_arg(*rt, ERR_NOT_FLOAT, STR_SPHERE, NO_FREE_MLX), 1);
	if (add_sp_second_part(rt, line, i, new_sphere))
		return (ERROR);
	add_sphere_lst(rt, new_sphere);
	return (0);
}

//check and add pl and its values
int	add_plane(t_rt *rt, char *line)
{
	int		i;
	t_plane	*new_plane;

	new_plane = init_plane();
	if (!new_plane)
		return (print_error(*rt, ERR_MALLOC, NO_FREE_MLX));
	i = 2;
	if (skip_space_check_not_enough_values(line, &i))
		return (free_plane(&new_plane), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_PLANE, NO_FREE_MLX));
	if (check_is_a_vector(line, &i, &new_plane->pl_point))
		return (free_plane(&new_plane), \
			print_error_arg(*rt, ERR_NOT_VECTOR, STR_PLANE, NO_FREE_MLX), 1);
	if (skip_space_check_not_enough_values(line, &i))
		return (free_plane(&new_plane), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_PLANE, NO_FREE_MLX));
	if (check_is_a_vector_range(line, &i, &new_plane->pl_normal))
		return (free_plane(&new_plane), \
			print_error_arg(*rt, ERR_VECTOR_RANGE, STR_PLANE, NO_FREE_MLX), 1);
	if (add_pl_second_part(rt, line, i, new_plane))
		return (ERROR);
	new_plane->pl_normal = v_normalized(new_plane->pl_normal);
	add_plane_lst(rt, new_plane);
	return (0);
}

//check and add cy and its values
int	add_cylinder(t_rt *rt, char *line)
{
	int			i;
	t_cylinder	*new_cyl;

	new_cyl = init_cylinder();
	if (!new_cyl)
		return (print_error(*rt, ERR_MALLOC, NO_FREE_MLX));
	i = 2;
	if (skip_space_check_not_enough_values(line, &i))
		return (free_cylinder(&new_cyl), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CYL, NO_FREE_MLX));
	if (check_is_a_vector(line, &i, &new_cyl->cy_center))
		return (free_cylinder(&new_cyl), \
			print_error_arg(*rt, ERR_NOT_VECTOR, STR_CYL, NO_FREE_MLX), 1);
	if (skip_space_check_not_enough_values(line, &i))
		return (free_cylinder(&new_cyl), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CYL, NO_FREE_MLX));
	if (check_is_a_vector_range(line, &i, &new_cyl->cy_axis))
		return (free_cylinder(&new_cyl), \
			print_error_arg(*rt, ERR_VECTOR_RANGE, STR_CYL, NO_FREE_MLX), 1);
	if (add_cy_second_part(rt, line, i, new_cyl) > 0)
		return (ERROR);
	calc_cy_values(new_cyl);
	add_cylinder_lst(rt, new_cyl);
	return (0);
}
