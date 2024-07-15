/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:43:50 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/19 19:58:46 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int		lenone;
	unsigned int		lentwo;
	char				*arr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lenone = (unsigned int)ft_strlen(s1);
	lentwo = (unsigned int)ft_strlen(s2);
	arr = (char *) malloc(sizeof(char) * (lenone + lentwo + 1));
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, s1, lenone + 1);
	ft_strlcat(arr, s2, lenone + lentwo + 1);
	return (arr);
}
