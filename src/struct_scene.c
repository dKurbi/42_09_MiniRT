/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:48:23 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/04/27 17:24:20 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	add_line_to_scene(t_rt *rt, char *line)
{
	if (!ft_strncmp(line, "A", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (add_ambient_light(&rt, line));
	else if (!ft_strncmp(line, "C", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (add_camera(&rt, line));
	else if (!ft_strncmp(line, "L", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (add_light(&rt, line));
	else if (!ft_strncmp(line, "sp", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (add_sphere(&rt, line));
	else if (!ft_strncmp(line, "pl", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (add_plane(&rt, line));
	else if (!ft_strncmp(line, "cy", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (add_cylinder(&rt, line));
	else
		return (print_error(*rt, ERR_VALUE_NOT_SCENE, NO_FREE_MLX));
	return (0);
}