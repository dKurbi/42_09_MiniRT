/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_capital.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:13 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/20 18:37:13 by dkurcbar         ###   ########.fr       */
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
	if (!(rt->scene.c_fov >= 0 && rt->scene.c_fov <= 180))
		return (print_error_arg(*rt, ERR_RANGE, STR_CAMERA, NO_FREE_MLX));
	rt->scene.c_fov= get_rad(rt->scene.c_fov);
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
	return (0);
}
