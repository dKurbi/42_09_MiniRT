/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/24 05:07:47 by iassambe         ###   ########.fr       */
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

int	free_rt(t_rt *rt)
{
	if (rt->line || rt->line != NULL)
		free_str(&rt->line);
	ft_close(&rt->fd);
	return (1);
}
