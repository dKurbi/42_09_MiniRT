/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:32:56 by iassambe          #+#    #+#             */
/*   Updated: 2024/08/17 08:43:44 by iassambe         ###   ########.fr       */
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
