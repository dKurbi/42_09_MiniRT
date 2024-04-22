/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/22 18:10:54 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char	*free_str(char **s)
{
	if (!*s)
		return (NULL);
	free(*s);
	*s = NULL;
	return (NULL);
}

int	free_rt(t_rt *rt)
{
	free_str(&rt->line);
	return (1);
}
