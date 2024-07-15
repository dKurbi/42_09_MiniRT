/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/26 16:07:49 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//mac doesnt have mlx_destroy_display
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

//destroy all in mlx
void	free_mlx(t_mlx *rtmlx)
{
	mlx_destroy_image(rtmlx->mlx_ptr, rtmlx->img);
	mlx_destroy_window(rtmlx->mlx_ptr, rtmlx->win);
	destroy_display(rtmlx->mlx_ptr);
}

int	free_rt(t_rt *rt, int if_free_mlx)
{
	if (rt->line || rt->line != NULL)
		free_str(&rt->line);
	ft_close(&rt->fd);
	free_double_str(&rt->split);
	free_sphere(&rt->scene.sp);
	free_plane(&rt->scene.pl);
	free_cylinder(&rt->scene.cy);
	if (if_free_mlx == 1)
		free_mlx(&rt->rtmlx);
	return (1);
}
