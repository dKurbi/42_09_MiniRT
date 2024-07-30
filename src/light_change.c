/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:57:52 by diego             #+#    #+#             */
/*   Updated: 2024/07/30 17:20:43 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	amb_light_more_bright(t_rt *rt)
{
	if (rt->scene.a_l_ratio * 1.1 < 1)
		rt->scene.a_l_ratio = rt->scene.a_l_ratio * 1.1;
}

void	amb_light_less_bright(t_rt *rt)
{
	if (rt->scene.a_l_ratio / 1.1 > 0)
		rt->scene.a_l_ratio = rt->scene.a_l_ratio / 1.1;
}
