/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:32:56 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/26 18:04:13 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//when did something in screen with mouse
int	event_mouse(int mouse, t_rt *rt)
{
	printf("mouse pressed - %d\n", mouse);
	(void)rt;
	return (0);
}

//when pressed key in screen
int	event_key(int key, t_rt *rt)
{
	printf("key pressed - %d\n", key);
	if (key == KEY_ESC)
		return (event_destroy(rt));
	else if (key == KEY_R)
	{
		cam_spin(rt, 0.17444);
		raytracing(rt);
	}	
	else if (key == KEY_T)
	{
		cam_spin(rt, -0.17444);
		raytracing(rt);
	}	
	else if (key == KEY_ARROW_LEFT)
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
	else if (key == KEY_Z)
	{
		cam_m_fwd(rt, -10);
		raytracing(rt);
	}	
	else if (key == KEY_A)
	{
		cam_m_fwd(rt, 10);
		raytracing(rt);
	}
	else if (key == KEY_B)
	{
		amb_light_more_bright(rt);
		raytracing(rt);
	}	
	else if (key == KEY_V)
	{
		amb_light_less_bright(rt);
		raytracing(rt);
	}
	return (0);
	
}

//destroy window, free rt and exit
int	event_destroy(t_rt *rt)
{
	free_rt(rt, FREE_MLX);
	ft_printf("Exiting miniRT...\n");
	exit(EXIT_SUCCESS);
	return (0);
}
