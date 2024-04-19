/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:56:46 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/19 18:31:05 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	first;
	char			*arr;
	unsigned int	last;

	first = 0;
	if (!(s1) || !(set))
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	if (*set == '\0')
		return (ft_strdup(s1));
	while (s1[first] != '\0' && ft_strchr(set, s1[first]))
		first++;
	last = (unsigned int)ft_strlen(s1) - 1;
	while (first < last && ft_strchr(set, s1[last]))
		last--;
	arr = (char *) malloc(sizeof(char) * (last - first + 2));
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, &s1[first], last - first + 2);
	return (arr);
}
