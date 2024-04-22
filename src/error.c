/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:30:33 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/22 05:35:41 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	print_error_exit(t_rt rt, char *s_err, int status)
{
	if (write(STDERR_FILENO, STR_MINIRT, ft_strlen(STR_MINIRT)) < 0)//linux -O3 flag error for compile
	{
		free_rt(&rt);
		exit(status);
	}
	if (write(STDERR_FILENO, s_err, ft_strlen(s_err)) < 0)//linux -O3 flag error for compile
	{
		free_rt(&rt);
		exit(status);
	}
	free_rt(&rt);
	exit(status);
	return (status);
}
