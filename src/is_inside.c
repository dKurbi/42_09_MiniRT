/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:06:22 by diego             #+#    #+#             */
/*   Updated: 2024/08/20 02:51:32 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minirt.h"

//print just black screen
void	print_black(t_rt *rt)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			pixel_put(*rt, x, y, 0);
		}
	}
	mlx_put_image_to_window(rt->rtmlx.mlx_ptr, rt->rtmlx.win, \
			rt->rtmlx.img, 0, 0);
}

//if the point is inside - 1
int	is_inside_sp(t_sphere sp, t_vector point)
{
	double	dist;

	dist = v_lenght(v_rest(sp.sp_center, point));
	if (dist <= sp.sp_diam / 2)
		return (1);
	return (0);
}

//if the point is inside - 1
int	is_inside_pl(t_plane pl, t_vector point)
{
	t_vector	line;

	line = v_rest(pl.pl_point, point);
	if (fabs(v_dot(pl.pl_normal, line)) < EPSILON)
		return (1);
	return (0);
}

//if the point is inside - 1
int	is_inside_cy(t_cylinder cy, t_vector point)
{
	t_vector	to_point;
	t_vector	projection;
	t_vector	distance_vector;
	float		t;
	float		distance;

	to_point = v_rest(point, cy.cy_base);
	t = v_dot(to_point, cy.cy_axis);
	projection = v_add(cy.cy_base, v_expand(cy.cy_axis, t));
	distance_vector = v_rest(point, projection);
	distance = v_lenght(distance_vector);
	if (distance > cy.cy_diam / 2 || t < 0 || t > cy.cy_height)
		return (0);
	return (1);
}
