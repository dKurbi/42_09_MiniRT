/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:40:35 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/16 20:00:48 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	if ((size * count) > 65535)
		return (NULL);
	arr = (char *)malloc(size * count);
	if (arr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
