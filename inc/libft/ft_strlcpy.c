/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:34:40 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/17 18:08:22 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	jlen;

	jlen = 0;
	while (src[jlen] != '\0' && (jlen + 1) < dstsize)
	{
		dst[jlen] = src[jlen];
		jlen++;
	}
	if (dstsize != 0)
		dst[jlen] = '\0';
	while (src[jlen] != '\0')
		jlen++;
	return (jlen);
}
