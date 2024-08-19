/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:37:07 by iassambe          #+#    #+#             */
/*   Updated: 2024/08/19 17:38:26 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//if pressed keys are arrows
void	event_key_rotate(int key, t_rt *rt)
{
	if (key == KEY_ARROW_LEFT)
	{
		cam_m_h(rt, -0.17444);
		raytracing(rt);
	}
	else if (key == KEY_ARROW_RIGHT)
	{
		cam_m_h(rt, 0.17444);
		raytracing(rt);
	}
	else if (key == KEY_ARROW_UP)
	{
		cam_m_v(rt, 0.17444);
		raytracing(rt);
	}
	else if (key == KEY_ARROW_DOWN)
	{
		cam_m_v(rt, -0.17444);
		raytracing(rt);
	}
}

//if pressed key for zoom or bright
void	event_key_zoom_bright(int key, t_rt *rt)
{
	if (key == KEY_B)
	{
		amb_light_more_bright(rt);
		raytracing(rt);
	}
	else if (key == KEY_N)
	{
		amb_light_less_bright(rt);
		raytracing(rt);
	}
	else if (key == KEY_PLUS)
	{
		if (zoom_in(rt))
			raytracing(rt);
	}
	else if (key == KEY_MINUS)
	{
		if (zoom_out(rt))
			raytracing(rt);
	}
}

void	event_key_spin(int key, t_rt *rt)
{
	if (key == KEY_R)
	{
		cam_spin(rt, 0.17444);
		raytracing(rt);
	}
	else if (key == KEY_T)
	{
		cam_spin(rt, -0.17444);
		raytracing(rt);
	}
}

void	event_key_move(int key, t_rt *rt)
{
	if (key == KEY_S)
	{
		cam_m_fwd(rt, -10);
		raytracing(rt);
	}
	else if (key == KEY_W)
	{
		cam_m_fwd(rt, 10);
		raytracing(rt);
	}
	else if (key == KEY_D)
	{
		cam_m_r_l(rt, 10);
		raytracing(rt);
	}
	else if (key == KEY_A)
	{
		cam_m_r_l(rt, -10);
		raytracing(rt);
	}
}
