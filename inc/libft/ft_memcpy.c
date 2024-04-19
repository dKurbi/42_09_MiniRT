/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:09 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/17 14:32:04 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*arrdst;
	const char	*arrsrc;

	arrdst = (char *)dst;
	arrsrc = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		arrdst[i] = arrsrc[i];
		i++;
	}
	return (dst);
}
