/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:05:00 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 20:01:51 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	rtnew(t_rt *rt, int ac, char **av)
{
	rt->ac = ac;
	rt->av = av;
	rt->fd = -1;
	rt->line = NULL;
	rt->split = NULL;
}

void	mlxnew(t_rt *rt)
{
	rt->rtmlx.init = mlx_init();
	rt->rtmlx.win = mlx_new_window(rt->rtmlx.init, WIN_X, WIN_Y, "miniRT");
	rt->rtmlx.img = mlx_new_image(rt->rtmlx.init, WIN_X, WIN_Y);
	rt->rtmlx.addr = mlx_get_data_addr(rt->rtmlx.img, \
					&rt->rtmlx.bitspp, &rt->rtmlx.line_len, &rt->rtmlx.endian);
}
