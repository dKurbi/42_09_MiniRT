/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:33:20 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/20 20:02:34 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vector	v_expand(t_vector v, double k)
{
	t_vector	v_ret;

	v_ret.x = v.x * k;
	v_ret.y = v.y * k;
	v_ret.z = v.z * k;
	return (v_ret);
}

t_vector	v_add(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.x + v2.x;
	v_ret.y = v1.y + v2.y;
	v_ret.z = v1.z + v2.z;
	return (v_ret);
}

t_vector	v_rest(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.x - v2.x;
	v_ret.y = v1.y - v2.y;
	v_ret.z = v1.z - v2.z;
	return (v_ret);
}

double	v_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	v_cross(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.y * v2.z - v1.z * v2.y;
	v_ret.y = v1.z * v2.x - v1.x * v2.z;
	v_ret.z = v1.x * v2.y - v1.y * v2.x;
	return (v_ret);
}
