/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:05:00 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/26 16:07:55 by diego            ###   ########.fr       */
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
	rt->a_l_count = 0;
	rt->c_count = 0;
	rt->l_count = 0;
	rt->aspect_ratio = WIN_X / WIN_Y;
}

void	mlxnew(t_rt *rt)
{
	rt->rtmlx.mlx_ptr = mlx_init();
	rt->rtmlx.win = mlx_new_window(rt->rtmlx.mlx_ptr, WIN_X, WIN_Y, "miniRT");
	rt->rtmlx.img = mlx_new_image(rt->rtmlx.mlx_ptr, WIN_X, WIN_Y);
	rt->rtmlx.addr = mlx_get_data_addr(rt->rtmlx.img, \
					&rt->rtmlx.bitspp, &rt->rtmlx.line_len, &rt->rtmlx.endian);
}

t_sphere	*init_sphere(void)
{
	t_sphere	*new_sphere;

	new_sphere = (t_sphere *) malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (NULL);
	new_sphere->sp_diam = 0;
	new_sphere->next = NULL;
	return (new_sphere);
}

t_plane	*init_plane(void)
{
	t_plane	*new_plane;

	new_plane = (t_plane *) malloc(sizeof(t_plane));
	if (!new_plane)
		return (NULL);
	new_plane->next = NULL;
	return (new_plane);
}

t_cylinder	*init_cylinder(void)
{
	t_cylinder	*new_cylinder;

	new_cylinder = (t_cylinder *) malloc(sizeof(t_cylinder));
	if (!new_cylinder)
		return (NULL);
	new_cylinder->cy_diam = 0;
	new_cylinder->cy_height = 0;
	new_cylinder->next = NULL;
	return (new_cylinder);
}
