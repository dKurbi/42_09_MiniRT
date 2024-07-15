/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:42:21 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/19 16:05:19 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	stlen;

	stlen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (stlen < start)
		return (ft_strdup(""));
	if ((stlen - start) < len)
		len = stlen - start;
	arr = (char *) malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, &s[start], len + 1);
	arr[len] = '\0';
	return (arr);
}
