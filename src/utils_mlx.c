/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 05:23:50 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/26 16:35:40 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//custom mlx_pixel_put
void	pixel_put(t_rt rt, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIN_X && y < WIN_Y)
	{
		dst = rt.rtmlx.addr + (y * rt.rtmlx.line_len \
									+ x * (rt.rtmlx.bitspp / 8));
		*(unsigned int *)dst = color;
	}
}

//return int color from 3 int: r, g, b
int	color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
