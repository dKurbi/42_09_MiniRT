/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:54:23 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/26 15:00:25 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	make_ray(t_vector2 point, t_vector start, t_vector c_direction)
{
	t_ray	new_ray;

	new_ray.direction = rotation_x(c_direction, point.x);
    new_ray.direction = rotation_y(new_ray.direction, point.y);
    new_ray.start = start;
    new_ray.len = 1;
    
	return (new_ray);
}
