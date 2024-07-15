/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:53:44 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/27 15:56:54 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//close force
void	ft_close(int *fd)
{
	if (*fd < 0)
		return ;
	close(*fd);
	*fd = -1;
}

//return i that skips spaces
int	skip_spaces(char *s, int i_provided)
{
	int	i;

	if (!s)
		return (0);
	i = i_provided;
	while (s[i] && \
		(s[i] == SPACE || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'))
		i++;
	return (i);
}

//if space or something like this - return 1, if NOT space - return 0
int	if_space(char c)
{
	if (c == SPACE || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

//strlen for **s
int	len_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}
