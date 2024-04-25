/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:33:48 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 21:29:14 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_value_scene_quantity(t_rt rt)
{
	(void)rt;
	return (0);	
}

int	check_correct_value_fd(t_rt rt)
{
	rt.fd = open(rt.av[1], O_RDONLY);
	rt.line = get_next_line(rt.fd);
	while (rt.line != NULL)
	{
		if (check_if_empty_str(rt.line) == 0)
		{
			if (check_value_scene_quantity(rt) > 0)
				return (1);
		}
		free(rt.line);
		rt.line = get_next_line(rt.fd);
	}
	ft_close(&rt.fd);
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
	else if (check_correct_value_fd(rt))
		return (ERROR);
		//return (print_error_arg(rt, ERR_VALUE, rt.av[1], NO_FREE_MLX));
	return (0);
}
