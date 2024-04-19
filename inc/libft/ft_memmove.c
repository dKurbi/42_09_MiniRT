/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:08:12 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/18 16:36:21 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_else(char *arrdst, const char *arrsrc, size_t i)
{
	while (0 < i)
	{
		arrdst[i - 1] = arrsrc[i - 1];
		i--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*arrdst;
	const char	*arrsrc;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (len == 0 || dst == src)
		return (dst);
	arrsrc = (const char *)src;
	arrdst = (char *)dst;
	if (arrdst < arrsrc)
	{
		while (i < len)
		{
			arrdst[i] = arrsrc[i];
			i++;
		}
	}
	else
	{
		i = len;
		ft_memmove_else(arrdst, arrsrc, i);
	}
	return (dst);
}
