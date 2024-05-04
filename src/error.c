/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:30:33 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/30 01:53:28 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

////linux -O3 err - if (write...
/*print error, !!! free t_rt !!!
flag_mlx if need to destroy mlx (segfault can ocurr)
Flag passing flag_mlx: 1 - free mlx(destroy), 0 - dont*/
int	print_error(t_rt rt, char *s_err, int flag_mlx)
{
	if (!s_err)
		return (0);
	if (write(STDERR_FILENO, STR_MINIRT, ft_strlen(STR_MINIRT)) < 0 || \
	write(STDERR_FILENO, s_err, ft_strlen(s_err)) < 0)
	{
		free_rt(&rt, flag_mlx);
		exit(ERROR);
	}
	free_rt(&rt, flag_mlx);
	return (1);
}

int	print_error_arg(t_rt rt, char *s_err, char *s_arg, int flag_mlx)
{
	if (!s_err)
		return (0);
	if (write(STDERR_FILENO, STR_MINIRT, ft_strlen(STR_MINIRT)) < 0 || \
	write(STDERR_FILENO, s_arg, ft_strlen(s_arg)) < 0 || \
	write(STDERR_FILENO, ": ", ft_strlen(": ")) < 0 || \
	write(STDERR_FILENO, s_err, ft_strlen(s_err)) < 0)
	{
		free_rt(&rt, flag_mlx);
		exit(ERROR);
	}
	free_rt(&rt, flag_mlx);
	return (1);
}
