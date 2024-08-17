/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:32:56 by iassambe          #+#    #+#             */
/*   Updated: 2024/08/17 22:51:09 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//when did something in screen with mouse
int	event_mouse(int mouse, t_rt *rt)
{
	printf("mouse pressed - %d\n", mouse);
	if (mouse == MOUSE_LEFT)
	{
		amb_light_more_bright(rt);
		raytracing(rt);
	}
	else if (mouse == MOUSE_RIGHT)
	{
		amb_light_less_bright(rt);
		raytracing(rt);
	}
	else if (mouse == MOUSE_SCROLL_UP)
	{
		if (zoom_in(rt))
			raytracing(rt);
	}
	else if (mouse == MOUSE_SCROLL_DOWN)
	{
		if (zoom_out(rt))
			raytracing(rt);
	}
	return (0);
}

//when pressed key in screen
int	event_key(int key, t_rt *rt)
{
	printf("key pressed - %d\n", key);
	if (key == KEY_ESC)
		return (event_destroy(rt));
	else if (key == KEY_M)
		print_menu();
	event_key_spin(key, rt);
	event_key_move(key, rt);
	event_key_rotate(key, rt);
	event_key_zoom_bright(key, rt);
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
