/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:39 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/06/11 16:07:14 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//square of len of vector
double	v_lenght2(t_vector vector)
{
	return (pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

//len of vector
double	v_lenght(t_vector vector)
{
	return (sqrt(v_lenght2(vector)));
}

//get normal vector
t_vector	v_normalized(t_vector vector)
{
	t_vector	v_ret;
	double		len;

	len = v_lenght(vector);
	if (len == 0)
		return (vector);
	v_ret.x = vector.x / len;
	v_ret.y = vector.y / len;
	v_ret.z = vector.z / len;
	return (v_ret);
}
t_vector v_new(double x, double y, double z)
{
	t_vector new;

	new.x = x;
	new.y = y;
	new.z = z;

	return (new);
}