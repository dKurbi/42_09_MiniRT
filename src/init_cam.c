/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:04:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/08/14 17:23:42 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersec	new_intersec(void)
{
	t_intersec	new_intersec;

	new_intersec.object = NO_INTER;
	new_intersec.index = -1;
	new_intersec.t1 = -1;
	new_intersec.t2 = -1;
	return (new_intersec);
}

void	init_cam(t_rt *rt)
{
	print_scene(rt->scene);
}
