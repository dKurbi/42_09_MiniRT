/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_lower_second.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:18:13 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/09 05:27:06 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//second part sphere because norminette
int	add_sp_second_part(t_rt *rt, char *line, int i, t_sphere *new_sp)
{
	if (skip_space_check_not_enough_values(line, &i))
		return (free_sphere(&new_sp), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_SPHERE, NO_FREE_MLX));
	if (check_is_a_rgb(line, &i, &new_sp->sp_color))
		return (free_sphere(&new_sp), \
			print_error_arg(*rt, ERR_RGB, STR_SPHERE, NO_FREE_MLX), 1);
	if (empty_after_line(line, i) == 0)
		return (free_sphere(&new_sp), \
			print_error_arg(*rt, ERR_VALUE_MUCH, STR_SPHERE, NO_FREE_MLX), 1);
	return (0);
}

//second part plane because norminette
int	add_pl_second_part(t_rt *rt, char *line, int i, t_plane *new_pl)
{
	if (skip_space_check_not_enough_values(line, &i))
		return (free_plane(&new_pl), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_PLANE, NO_FREE_MLX));
	if (check_is_a_rgb(line, &i, &new_pl->pl_color))
		return (free_plane(&new_pl), \
			print_error_arg(*rt, ERR_RGB, STR_PLANE, NO_FREE_MLX), 1);
	if (empty_after_line(line, i) == 0)
		return (free_plane(&new_pl), \
			print_error_arg(*rt, ERR_VALUE_MUCH, STR_PLANE, NO_FREE_MLX), 1);
	return (0);
}

//second part cylinder because norminette
int	add_cy_second_part(t_rt *rt, char *line, int i, t_cylinder *new_cy)
{
	if (skip_space_check_not_enough_values(line, &i))
		return (free_cylinder(&new_cy), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CYL, NO_FREE_MLX));
	if (check_is_a_float(line, &i, &new_cy->cy_diam))
		return (free_cylinder(&new_cy), \
			print_error_arg(*rt, ERR_NOT_FLOAT, STR_CYL, NO_FREE_MLX), 1);
	if (skip_space_check_not_enough_values(line, &i))
		return (free_cylinder(&new_cy), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CYL, NO_FREE_MLX));
	if (check_is_a_float(line, &i, &new_cy->cy_height))
		return (free_cylinder(&new_cy), \
			print_error_arg(*rt, ERR_NOT_FLOAT, STR_CYL, NO_FREE_MLX), 1);
	if (skip_space_check_not_enough_values(line, &i))
		return (free_cylinder(&new_cy), \
			print_error_arg(*rt, ERR_NOT_ENOUGH, STR_CYL, NO_FREE_MLX));
	if (check_is_a_rgb(line, &i, &new_cy->cy_color))
		return (free_cylinder(&new_cy), \
			print_error_arg(*rt, ERR_RGB, STR_CYL, NO_FREE_MLX), 1);
	if (empty_after_line(line, i) == 0)
		return (free_cylinder(&new_cy), \
			print_error_arg(*rt, ERR_VALUE_MUCH, STR_CYL, NO_FREE_MLX), 1);
	return (0);
}
