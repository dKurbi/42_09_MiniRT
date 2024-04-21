/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:30:33 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/21 20:18:09 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	print_error_exit(t_rt rt, char *s_err, int status)
{
	write(STDERR_FILENO, STR_MINIRT, ft_strlen(STR_MINIRT));
	write(STDERR_FILENO, s_err, ft_strlen(s_err));
	free_rt(&rt);
	exit(status);
	return (status);
}
