/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:32:56 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 17:20:03 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	event_key(int key, t_rt *rt)
{
	printf("key - %d\n", key);//debug print for Mac, Linux
	if (key == KEY_ESC)
	{
		free_rt(rt, FREE_MLX);
		ft_printf("Exit\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	event_destroy(t_rt *rt)
{
	free_rt(rt, FREE_MLX);
	ft_printf("Exit\n");
	exit(EXIT_SUCCESS);
}
