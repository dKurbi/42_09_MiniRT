/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:42:05 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/16 20:19:18 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenneed;

	i = 0;
	lenneed = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (needle[lenneed] != '\0')
		lenneed++;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (i + j) < len)
			j++;
		if (j == lenneed)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
