/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 05:23:50 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/24 18:23:14 by iassambe         ###   ########.fr       */
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
