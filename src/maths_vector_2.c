/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:39 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/24 18:31:16 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	v_lenght2(t_vector vector)
{
	return (pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

double	v_lenght(t_vector vector)
{
	return (sqrt(v_lenght2(vector)));
}

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
