/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:04:56 by diego             #+#    #+#             */
/*   Updated: 2024/08/14 16:21:21 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	cam_spin(t_rt *rt, double ang)
{
	rt->scene.v_right = v_normalized(rotation_axis(rt->scene.v_right, \
		rt->scene.c_dir, ang));
	rt->scene.v_up = v_normalized(rotation_axis(rt->scene.v_up, \
		rt->scene.c_dir, ang));
}

void	cam_m_h(t_rt *rt, double ang)
{
	rt->scene.c_dir = v_normalized(rotation_axis(rt->scene.c_dir, \
		rt->scene.v_up, ang));
	rt->scene.v_right = v_normalized(rotation_axis(rt->scene.v_right, \
		rt->scene.v_up, ang));
}

void	cam_m_v(t_rt *rt, double ang)
{
	rt->scene.c_dir = v_normalized(rotation_axis(rt->scene.c_dir, \
		rt->scene.v_right, ang));
	rt->scene.v_up = v_normalized(rotation_axis(rt->scene.v_up, \
		rt->scene.v_right, ang));
}

void	cam_m_fwd(t_rt *rt, int distance)
{
	rt->scene.c_pos = v_add(rt->scene.c_pos, \
		v_expand(rt->scene.c_dir, distance));
}
