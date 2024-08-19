/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:32:56 by iassambe          #+#    #+#             */
/*   Updated: 2024/08/19 17:31:38 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//when pressed key in screen
int	event_key(int key, t_rt *rt)
{
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
