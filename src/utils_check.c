/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:05:15 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/07 03:05:24 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//check if after checking all, there is empty or only spaces
int	empty_after_line(char *line, int i_provide)
{
	i_provide = skip_spaces(line, i_provide);
	if (i_provide >= (int)ft_strlen(line))
		return (1);
	return (0);
}

//limit: 0 and 255
//0 if in limit, 1 if out of limit
int	rgb_limit(int r, int g, int b)
{
	if (!(r >= 0 && r <= 255) || \
		!(g >= 0 && g <= 255) || \
		!(b >= 0 && b <= 255))
		return (1);
	return (0);
}
