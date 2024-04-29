/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:53:17 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/29 19:48:23 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//limit: 0 and 255
//0 if in limit, 1 if out of limit
int	rgb_limit(int r, int g, int b)
{
	if (!(r >= 0 && r <= 255) || \
		!(g >= 0 && g <= 255) || \
		!(b >= 0 && b <= 255))
		return (1);
	return (0);
}