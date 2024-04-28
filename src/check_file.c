/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:33:48 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/28 17:38:40 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
what it checks:
check if it doesnt start for letter (sp, C, etc..) or only nums (132 43 24 2)
check if this word is from scene description
check if capital rules (A, C, etc..) are appeared once
*/
int	check_value_str_num_correctstr_capital(t_rt rt)
{
	(void)rt;
	return (0);
}

//check if it passed like iin this form: sp(0, sp 43//, etc...)
int	check_value_syntax(t_rt rt)
{
	(void)rt;
	return (0);
}

/*main check: check if every line has the right order, number, syntax, etc.
scenes:
A, C, L, sp, pl, cy
*/
int	check_save_value(t_rt rt)
{
	char	*line;

	rt.fd = open(rt.av[1], O_RDONLY);
	line = get_next_line(rt.fd);
	while (line != NULL)
	{
		if (check_if_empty_str(line) == 0)
		{
			if (add_line_to_scene(rt, line))
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
	else if (check_save_value(rt))
		return (ERROR);
		//return (print_error_arg(rt, ERR_VALUE, rt.av[1], NO_FREE_MLX));
	return (0);
}
