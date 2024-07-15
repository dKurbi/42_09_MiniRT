/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:54:23 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/07/15 13:34:47 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	make_ray(t_vector2 point, t_rt rt)
{
	t_ray	new_ray;
		
	new_ray.direction = v_add(rt.scene.c_dir, v_expand(rt.scene.v_right, point.x));
	new_ray.direction = v_add(new_ray.direction, v_expand(rt.scene.v_up, point.y));
	new_ray.direction = v_normalized(new_ray.direction);
	new_ray.start = rt.scene.c_pos;
	new_ray.len = 1;
	return (new_ray);
}
