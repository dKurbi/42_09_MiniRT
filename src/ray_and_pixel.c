/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:54:23 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/06/10 16:56:22 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	make_ray(t_vector2 point, t_rt rt)
{
	t_ray	new_ray;
	static 	int i;

	new_ray.direction = rotation_axis(rt.scene.c_dir, rt.scene.v_up, point.x);
	new_ray.direction = rotation_axis(new_ray.direction, \
		rt.scene.v_right, point.y);
	if (i++ < WIN_X )
	{
		printf("print n = %d, i = %d\n", (i -  1) / 10000, i - 1);
		printf("angle x = %f\n", point.x * 180 / M_PI);
		printf("angle y = %f\n\n", point.y * 180 / M_PI);
	}
	new_ray.start = rt.scene.c_pos;
	new_ray.len = 1;
	return (new_ray);
}
