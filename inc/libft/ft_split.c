/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:30:04 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/24 15:28:31 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_leninword(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static size_t	ft_split_words(char const *s, char c)
{
	size_t	i;
	size_t	numwords;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	numwords = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i == len)
			break ;
		numwords++;
		i = i + ft_split_leninword(&s[i], c);
	}
	return (numwords);
}

static char	**ft_split_fail(char **splited)
{
	size_t	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (NULL);
}

static char	**ft_split_loop(char const *s, char c, char **splited)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			splited[j] = ft_substr(s, i, ft_split_leninword(s, c));
			if (!splited[j++])
				return (ft_split_fail(splited));
			s = s + ft_split_leninword(s, c);
		}
		else
			s++;
	}
	splited[j] = NULL;
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_split_words(s, c);
	splited = (char **)malloc(sizeof(char *) * (words + 1));
	if (splited == NULL)
		return (NULL);
	return (ft_split_loop(s, c, splited));
}
