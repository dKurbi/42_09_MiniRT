/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:31:58 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/23 16:45:27 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//get radian from degrees (angle)
double	get_radian(double angle)
{
	return (angle * (M_PI / 180.0));
}

//absolute number (or easier: positive)
double	absolute(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}
