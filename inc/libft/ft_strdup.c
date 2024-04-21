/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:03:31 by iassambe          #+#    #+#             */
/*   Updated: 2024/02/09 13:28:03 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*arr;
	unsigned int	lenstr;

	lenstr = 0;
	i = 0;
	if (!s1)
		return (NULL);
	while (s1[lenstr] != '\0')
		lenstr++;
	arr = (char *) malloc(sizeof(char) * (lenstr + 1));
	if (arr == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
