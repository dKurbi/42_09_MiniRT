/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:05:00 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/27 17:04:40 by dkurcbar         ###   ########.fr       */
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
	rt->scene.sp = NULL;
	rt->scene.pl = NULL;
	rt->scene.cy = NULL;
	rt->scene.a_l_ratio = -1;
	rt->scene.c_fov = -1;
	rt->scene.l_bright = -1;
}

void	mlxnew(t_rt *rt)
{
	rt->rtmlx.init = mlx_init();
	rt->rtmlx.win = mlx_new_window(rt->rtmlx.init, WIN_X, WIN_Y, "miniRT");
	rt->rtmlx.img = mlx_new_image(rt->rtmlx.init, WIN_X, WIN_Y);
	rt->rtmlx.addr = mlx_get_data_addr(rt->rtmlx.img, \
					&rt->rtmlx.bitspp, &rt->rtmlx.line_len, &rt->rtmlx.endian);
}

int	init_scene(t_rt rt)
{
	char	*line;

	line = get_next_line(rt.fd);
	while (line)
	{
		if (add_line_to_scene(rt, line) > 0)
		{
			free_str(&line);
			return (1);
		}
		free_str(&line);
		line = get_next_line(rt.fd);
	}
	return (0);
}
