/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:06:22 by diego             #+#    #+#             */
/*   Updated: 2024/08/14 16:30:12 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minirt.h"

void	print_black(t_rt *rt)
{
	int	y;
	int	x;

	y = -1;
	printf("THE CAM IS INSIDE\n");
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			pixel_put(*rt, x, y, 0);
		}
		mlx_put_image_to_window(rt->rtmlx.mlx_ptr, rt->rtmlx.win, \
			rt->rtmlx.img, 0, 0);
	}
}

int	is_inside_sp(t_sphere sp, t_rt rt)
{
	double	dist;

	dist = v_lenght(v_rest(sp.sp_center, rt.scene.c_pos));
	if (dist <= sp.sp_diam / 2)
		return (1);
	print_v("center sp: ", sp.sp_center);
	print_v("cam  posc: ", rt.scene.c_pos);
	printf("dist = %f, sp radius: %f\n", dist, sp.sp_diam / 2);
	return (0);
}

int	is_inside_pl(t_plane pl, t_rt rt)
{
	(void) pl;
	(void) rt;
	return (0);
}

// Función para verificar si un punto está dentro del cilindro
// retorna 1 si esta adentro y 0 sino
int	is_inside_cy(t_cylinder cy, t_rt rt)
{
	t_vector	to_point;
	t_vector	projection;
	t_vector	distance_vector;
	float		t;
	float		distance;

	to_point = v_rest(rt.scene.c_pos, cy.cy_base);
	t = v_dot(to_point, cy.cy_axis);
	projection = v_add(cy.cy_base, v_expand(cy.cy_axis, t));
	distance_vector = v_rest(rt.scene.c_pos, projection);
	distance = v_lenght(distance_vector);
	if (distance > cy.cy_diam / 2 || t < 0 || t > cy.cy_height)
		return (0);
	print_v("base cy: ", cy.cy_base);
	print_v("cam  posc: ", rt.scene.c_pos);
	printf("dist = %f, t = %f, cy radius: %f, cy height= %f\n", \
		distance, t, cy.cy_diam / 2, cy.cy_height);
	return (1);
}
