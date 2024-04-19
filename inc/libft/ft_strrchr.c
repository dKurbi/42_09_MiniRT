/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:26:27 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/18 20:29:02 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*arr;

	i = ft_strlen(s);
	arr = (char *)s;
	while (0 <= i)
	{
		if (arr[i] == (unsigned char)c)
			return (&arr[i]);
		i--;
	}
	return (0);
}
