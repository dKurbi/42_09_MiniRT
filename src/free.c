/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/01 20:24:01 by iassambe         ###   ########.fr       */
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

char	*free_double_str(char ***s)
{
	int	i;

	i = 0;
	if (!*s)
	{
		*s = NULL;
		return (NULL);
	}
	while ((*s)[i])
	{
		if ((*s)[i] != NULL)
			free((*s)[i]);
		i++;
	}
	free(*s);
	*s = NULL;
	return (NULL);
}

//destroy all in mlx
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
	free_double_str(&rt->split);
	return (1);
}
