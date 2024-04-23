/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/23 05:38:56 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char	*free_str(char **s)
{
	printf("our s - %s\n", *s);
	if (!*s | !s)
	{
		*s = NULL;
		return (NULL);
	}
	free(*s);
	*s = (void *)0;
	return (NULL);
}

int	free_rt(t_rt *rt)
{
	if (rt->line)
		free_str(&rt->line);
	return (1);
}
