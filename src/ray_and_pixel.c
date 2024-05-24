/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:54:23 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/24 01:38:20 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	make_ray(t_vector2 point)
{
	t_ray	new_ray;

	(void)point;
	(void)new_ray;
	new_ray.direction.x = 0;
	return (new_ray);
}
