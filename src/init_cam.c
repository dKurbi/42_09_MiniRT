/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:04:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/24 18:03:44 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_cam(t_rt *rt)
{
	printf("x - %f, y - %f, z - %f\n", rt->scene.c_foward.x, rt->scene.c_foward.y, rt->scene.c_foward.z);
	rt->scene.c_foward = v_normalized(v_rest(rt->scene.c_dir, rt->scene.c_dir));
	printf("x - %f, y - %f, z - %f\n", rt->scene.c_foward.x, rt->scene.c_foward.y, rt->scene.c_foward.z);
}
