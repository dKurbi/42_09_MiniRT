/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:07:34 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/19 15:11:20 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)s;
	while (arr[i] != '\0')
	{
		if ((char)arr[i] == (char)c)
			return (&arr[i]);
		i++;
	}
	if (arr[i] == (char)c || !c)
		return (&arr[i]);
	return (NULL);
}
