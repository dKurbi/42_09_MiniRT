/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_capital.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:13 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/04/27 18:00:39 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int add_ambient_light(t_rt *rt,char *line)
{
	int	i;

	i = 1;
	i = skip_spaces(line, i);
	if (check_is_a_float(line, &i &rt->scene.a_l_ratio))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_AMBIENT_LIGHT, NO_FREE_MLX));
	if (rt->scene.a_l_ratio < 0 || rt->scene.a_l_ratio > 1)
		return (print_error_arg(*rt, ERR_RANGE, STR_AMBIENT_LIGHT, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_rgb(line, &i, &rt->scene.a_l_color))
		return (print_error_arg(*rt, ERR_RGB, STR_AMBIENT_LIGHT, NO_FREE_MLX));
	if (!check_if_empty_str(&line[i]))
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_AMBIENT_LIGHT, NO_FREE_MLX));
	return (0);

}


int add_camera(t_rt *rt,char *line)
{
	int	i;

	i = 1;
	i = skip_spaces(line, i);
	if (check_is_a_vector(line, &i &rt->scene.c_pos))
		return (print_error_arg(*rt, ERR_NOT_VECTOR, STR_CAMERA, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_vector_normal(line, &i, &rt->scene.c_dir))
		return (print_error_arg(*rt, ERR_VECTOR_RANGE, STR_CAMERA, NO_FREE_MLX));
	if (check_is_a_float(line, &i &rt->scene.c_fov))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_CAMERA, NO_FREE_MLX));
	if (!(rt->scene.c_fov >= 0 && rt->scene.c_fov <= 180))
		return (print_error_arg(*rt, ERR_RANGE, STR_CAMERA, NO_FREE_MLX));
	if (!check_if_empty_str(&line[i]))
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_AMBIENT_LIGHT, NO_FREE_MLX));
	return (0);
	
}
int add_light(t_rt *rt,char *line)
{
	int	i;

	i = 1;
	i = skip_spaces(line, i);
	if (check_is_a_vector(line, &i &rt->scene.l_pos))
		return (print_error_arg(*rt, ERR_NOT_VECTOR, STR_LIGHT, NO_FREE_MLX));
	i = skip_spaces(line, i);
	if (check_is_a_float(line, &i, &rt->scene.l_bright))
		return (print_error_arg(*rt, ERR_NOT_FLOAT, STR_CAMERA, NO_FREE_MLX));
	if (!(rt->scene.l_bright >= 0.0 && rt->scene.l_bright <= 1.0))
		return (print_error_arg(*rt, ERR_RANGE, STR_CAMERA, NO_FREE_MLX));
	if (!check_if_empty_str(&line[i]))
		return (print_error_arg(*rt, ERR_VALUE_MUCH, STR_AMBIENT_LIGHT, NO_FREE_MLX));
	return (0);
	
}
