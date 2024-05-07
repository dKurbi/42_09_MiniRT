/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:33:48 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/07 09:23:07 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//adding, judging which scene is
int	add_line_to_scene(t_rt *rt, char *line)
{
	if (!line[1] || !line[2])
		return (print_error(*rt, ERR_VALUE_NOT_SCENE, NO_FREE_MLX));
	if (!ft_strncmp(line, "A", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (add_ambient_light(rt, line));
	else if (!ft_strncmp(line, "C", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (add_camera(rt, line));
	else if (!ft_strncmp(line, "L", 1) && (line[1] == ' ' || line[1] == '\t'))
		return (add_light(rt, line));
	else if (!ft_strncmp(line, "sp", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (add_sphere(rt, line));
	else if (!ft_strncmp(line, "pl", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (add_plane(rt, line));
	else if (!ft_strncmp(line, "cy", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (add_cylinder(rt, line));
	else
		return (print_error(*rt, ERR_VALUE_NOT_SCENE, NO_FREE_MLX));
	return (0);
}

/*main check: check if every line has the right order, number, syntax, etc.
scenes:
A, C, L, sp, pl, cy
*/
int	check_save_value(t_rt *rt)
{
	char	*line;

	rt->fd = open(rt->av[1], O_RDONLY);
	line = get_next_line(rt->fd);
	while (line != NULL)
	{
		if (check_if_empty_str(line) == 0)
		{
			if (add_line_to_scene(rt, line))
			{
				free(line);
				return (1);
			}
		}
		free_str(&line);
		line = get_next_line(rt->fd);
	}
	free_str(&line);
	ft_close(&rt->fd);
	if (rt->a_l_count != 1 || rt->c_count != 1 || rt->l_count != 1)
		return (print_error(*rt, ERR_A_C_L, NO_FREE_MLX));
	return (0);
}

//main file check
int	check_file(t_rt rt)
{
	rt.fd = open(rt.av[1], O_RDONLY);
	if (rt.fd < 0)
	{
		if (write(STDERR_FILENO, STR_MINIRT, ft_strlen(STR_MINIRT)) < 0)
			exit(free_rt(&rt, NO_FREE_MLX));
		perror(rt.av[1]);
		exit(free_rt(&rt, NO_FREE_MLX));
	}
	if (check_extension(rt.av) > 0)
		return (print_error_arg(rt, ERR_EXTENSION, rt.av[1], NO_FREE_MLX));
	else if (check_if_empty_fd(rt, rt.fd) > 0)
		return (print_error_arg(rt, ERR_EMPTY, rt.av[1], NO_FREE_MLX));
	return (0);
}
