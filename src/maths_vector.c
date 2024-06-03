/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:33:20 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/28 17:09:32 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//each pos is extended
t_vector	v_expand(t_vector v, double k)
{
	t_vector	v_ret;

	v_ret.x = v.x * k;
	v_ret.y = v.y * k;
	v_ret.z = v.z * k;
	return (v_ret);
}

//sum of vectors
t_vector	v_add(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.x + v2.x;
	v_ret.y = v1.y + v2.y;
	v_ret.z = v1.z + v2.z;
	return (v_ret);
}

//rest of vectors BUT: from v1 rest v2: "v1.xyz - v2.xyz" (minus)
t_vector	v_rest(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.x - v2.x;
	v_ret.y = v1.y - v2.y;
	v_ret.z = v1.z - v2.z;
	return (v_ret);
}

//scalar product (x1x2 + y1y2 + z1z2)
double	v_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

//new vector, perpendicular to v1 && v2
t_vector	v_cross(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.y * v2.z - v1.z * v2.y;
	v_ret.y = v1.z * v2.x - v1.x * v2.z;
	v_ret.z = v1.x * v2.y - v1.y * v2.x;
	return (v_ret);
}
