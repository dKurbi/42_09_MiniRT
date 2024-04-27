/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:53:44 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/27 02:32:23 by iassambe         ###   ########.fr       */
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
