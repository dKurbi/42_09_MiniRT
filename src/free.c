/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 20:37:34 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

#ifdef __linux__

void	destroy_display(void *mlx_ptr)
{
	mlx_destroy_display(mlx_ptr);
}

#else

void	destroy_display(void *mlx_ptr)
{
	(void)mlx_ptr;
}

#endif

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
	destroy_display(rtmlx->init);
}

int	free_rt(t_rt *rt, int if_free_mlx)
{
	if (rt->line || rt->line != NULL)
		free_str(&rt->line);
	ft_close(&rt->fd);
	if (if_free_mlx == 1)
		free_mlx(&rt->rtmlx);
	return (1);
}
