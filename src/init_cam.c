/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:04:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/26 13:09:55 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_cam(t_rt *rt)
{
	print_scene(rt->scene);
	//printf("x - %f, y - %f, z - %f\n", rt->scene.c_foward.x, rt->scene.c_foward.y, rt->scene.c_foward.z);
	rt->scene.c_foward = v_normalized(v_rest(rt->scene.c_dir, rt->scene.c_dir));
	//printf("x - %f, y - %f, z - %f\n", rt->scene.c_foward.x, rt->scene.c_foward.y, rt->scene.c_foward.z);
	print_v("foward after notmalize", rt->scene.c_foward);
}
