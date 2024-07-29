/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:44:04 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/07/29 13:04:13 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./minirt.h"

int zoom_in(t_rt *rt)
{
	if (rt->scene.c_fov * 180 * 0.9 / M_PI  > 4 )
	{
		rt->scene.c_fov = rt->scene.c_fov * 0.9;
		return (1);
	}	
	return (0);
}
int zoom_out(t_rt *rt)
{
	if (rt->scene.c_fov * 1.1 < M_PI /2 )
	{
		rt->scene.c_fov = rt->scene.c_fov / 0.9;
		return (1);
	}
	return (0);
}