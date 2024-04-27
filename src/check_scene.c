/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:58:53 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/27 21:09:43 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//check if passed argument is a float/int
int	check_is_a_float(char *line, int *i_pass, float *num_pass)
{
	int	point_count;

	point_count = 0;
	while (line[*i_pass])
	{
		if (line[*i_pass] == SPACE || line[*i_pass] == '\t' || \
			line[*i_pass] == '\v' || line[*i_pass] == '\n')
			break ;
		if (line[*i_pass] == POINT)
		{
			point_count++;
		}
		else if (!((line[*i_pass] >= '0' && line[*i_pass] <= '9') || \
				(line[*i_pass] == POINT)))
			return (1);
		*(i_pass)++;
	}
	return (0);
}