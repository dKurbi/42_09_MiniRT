/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:54:23 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/06/02 18:49:14 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	make_ray(t_vector2 point, t_rt rt)
{
	t_ray	new_ray;
	

	new_ray.direction = rotation_axis(rt.scene.c_dir, rt.scene.v_up, point.x);
	new_ray.direction = rotation_axis(new_ray.direction, rt.scene.v_right, point.y);
	new_ray.start = rt.scene.c_pos;
	new_ray.len = 1;
	return (new_ray);
}
