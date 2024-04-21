/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:06:01 by iassambe          #+#    #+#             */
/*   Updated: 2023/08/19 19:20:56 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_ft_strdup_modif(char *s1)
{
	unsigned int	i;
	char			*arr;
	unsigned int	lenstr;

	lenstr = 0;
	i = -1;
	lenstr = get_ft_strlen(s1);
	arr = (char *) malloc(sizeof(char) * (lenstr + 1));
	if (arr == NULL)
		return (NULL);
	while (s1[++i])
		arr[i] = s1[i];
	arr[i] = '\0';
	return (arr);
}

char	*get_ft_strjoin_modif(char *s1, char *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;
	size_t	len_s1;

	if (s1 == NULL)
		s1 = get_ft_strdup_modif("");
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = -1;
	len_s1 = get_ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (len_s1 + get_ft_strlen(s2) + 1));
	if (arr == NULL)
		return (get_free(&s1));
	while (s1[++i])
		arr[i] = s1[i];
	while (s2[++j])
		arr[i++] = s2[j];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*get_ft_strchr(char *s, int c)
{
	int		i;
	char	*arr;

	i = 0;
	if (s == NULL)
		return (NULL);
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

char	*get_ft_substr_modif(char *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	stlen;
	size_t	i;

	stlen = get_ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (stlen < start)
		return (get_ft_strdup_modif(""));
	if ((stlen - start) < len)
		len = stlen - start;
	arr = (char *) malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s[++start - 1] && i < len)
		arr[i++] = s[start - 1];
	arr[i] = '\0';
	return (arr);
}
