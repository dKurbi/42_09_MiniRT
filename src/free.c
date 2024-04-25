/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 03:15:41 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char	*free_str(char **s)
{
	if (!*s | !s)
	{
		*s = NULL;
		return (NULL);
	}
	free(*s);
	*s = NULL;
	return (NULL);
}

void	free_mlx(t_mlx *rtmlx)
{
	mlx_destroy_image(rtmlx->init, rtmlx->img);
	mlx_destroy_window(rtmlx->init, rtmlx->win);
	mlx_destroy_display(rtmlx->init);
}

int	free_rt(t_rt *rt)
{
	if (rt->line || rt->line != NULL)
		free_str(&rt->line);
	ft_close(&rt->fd);
	free_mlx(&rt->rtmlx);
	return (1);
}
