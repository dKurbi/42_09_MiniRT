/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:04:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/20 19:06:51 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void init_cam(t_rt *rt)
{
	rt->scene.c_foward = v_normalized(v_rest(rt->scene.c_dir, rt->scene.c_dir));
	
}