/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:50:03 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/16 20:16:37 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	j;
	size_t	lensrc;

	j = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (dstsize <= lendst)
		lensrc = lensrc + dstsize;
	else
		lensrc = lensrc + lendst;
	while (src[j] != '\0' && (lendst + 1) < dstsize)
	{
		dst[lendst] = src[j];
		lendst++;
		j++;
	}
	dst[lendst] = '\0';
	return (lensrc);
}
