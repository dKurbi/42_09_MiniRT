/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_capital.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:13 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/07/29 13:25:44 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//check and add A and its values
int	add_ambient_light(t_rt *rt, char *line)
{
	int	i;

	rt->a_l_count++;
	i = 1;
	if (skip_space_check_not_enough_values(line, &i))
		return (print_error_arg(*rt, ERR_NOT_ENOUGH, STR_AMBIENT, NO_FREE_MLX));
	if (check_is_a_float(line, &i, &rt->scene.a_l_ratio))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_AMBIENT, NO_FREE_MLX));
	if (rt->scene.a_l_ratio < 0 || rt->scene.a_l_ratio > 1)
		return (print_error_arg(*rt, ERR_RANGE, STR_AMBIENT, NO_FREE_MLX));
	if (skip_space_check_not_enough_values(line, &i))
		return (print_error_arg(*rt, ERR_NOT_ENOUGH, STR_AMBIENT, NO_FREE_MLX));
	if (check_is_a_rgb(line, &i, &rt->scene.a_l_color))
		return (print_error_arg(*rt, ERR_RGB, STR_AMBIENT, NO_FREE_MLX));
	if (empty_after_line(line, i) == 0)
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_AMBIENT, NO_FREE_MLX));
	return (0);
}

//check and add C and its values
int	add_camera(t_rt *rt, char *line)
{
	int	i;

	rt->c_count++;
	i = 1;
	if (skip_space_check_not_enough_values(line, &i))
		return (print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CAMERA, NO_FREE_MLX));
	if (check_is_a_vector(line, &i, &rt->scene.c_pos))
		return (print_error_arg(*rt, ERR_NOT_VECTOR, STR_CAMERA, NO_FREE_MLX));
	if (skip_space_check_not_enough_values(line, &i))
		return (print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CAMERA, NO_FREE_MLX));
	if (check_is_a_vector_range(line, &i, &rt->scene.c_dir))
		return (print_error_arg(*rt, ERR_VECTOR_RANGE, \
								STR_CAMERA, NO_FREE_MLX));
	if (skip_space_check_not_enough_values(line, &i))
		return (print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CAMERA, NO_FREE_MLX));
	if (check_is_a_float(line, &i, &rt->scene.c_fov))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_CAMERA, NO_FREE_MLX));
	if (!(rt->scene.c_fov > 0 && rt->scene.c_fov < 180))
		return (print_error_arg(*rt, ERR_RANGE, STR_CAMERA, NO_FREE_MLX));
	rt->scene.c_fov = get_radian(rt->scene.c_fov / 2);
	if (empty_after_line(line, i) == 0)
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_CAMERA, NO_FREE_MLX));
	return (0);
}

//check and add L and its values
int	add_light(t_rt *rt, char *line)
{
	int	i;

	rt->l_count++;
	i = 1;
	if (skip_space_check_not_enough_values(line, &i))
		return (print_error_arg(*rt, ERR_NOT_ENOUGH, STR_LIGHT, NO_FREE_MLX));
	if (check_is_a_vector(line, &i, &rt->scene.l_pos))
		return (print_error_arg(*rt, ERR_NOT_VECTOR, STR_LIGHT, NO_FREE_MLX));
	if (skip_space_check_not_enough_values(line, &i))
		return (print_error_arg(*rt, ERR_NOT_ENOUGH, STR_LIGHT, NO_FREE_MLX));
	if (check_is_a_float(line, &i, &rt->scene.l_bright))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_LIGHT, NO_FREE_MLX));
	if (!(rt->scene.l_bright >= 0.0 && rt->scene.l_bright <= 1.0))
		return (print_error_arg(*rt, ERR_RANGE, STR_LIGHT, NO_FREE_MLX));
	if (empty_after_line(line, i) == 0)
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_LIGHT, NO_FREE_MLX));
	add_light_as_sphere(rt);

	return (0);
}
void 	add_light_as_sphere(t_rt *rt)
{
	t_sphere	*new_sphere;
	int			intense;

	new_sphere = init_sphere();
	if (!new_sphere)
		print_error(*rt, ERR_MALLOC, NO_FREE_MLX);
	new_sphere->sp_center = rt->scene.l_pos;
	new_sphere->sp_diam = 1;
	intense = 255 * rt->scene.l_bright;
	new_sphere->sp_color = (t_rgb) {intense, intense, intense};
	add_sphere_lst(rt, new_sphere);

}