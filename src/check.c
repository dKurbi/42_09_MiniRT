/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:11:21 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/06 04:02:06 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//empty *s - 1; no empty - 0
int	check_if_empty_str(char *s)
{
	size_t	i;

	if (ft_strlen(s) == 0 || s[0] == '\0')
		return (1);
	i = 0;
	while (s && s[i] && (s[i] == SPACE || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

//if file is empty - 1, no empty - 0
int	check_if_empty_fd(t_rt rt, int fd)
{
	int	count_lines;
	int	count_empty;

	count_lines = 0;
	count_empty = 0;
	rt.line = get_next_line(rt.fd);
	if (!rt.line)
		return (1);
	while (rt.line != NULL)
	{
		if (check_if_empty_str(rt.line))
			count_empty++;
		free(rt.line);
		count_lines++;
		rt.line = get_next_line(fd);
	}
	ft_close(&fd);
	if (count_lines == count_empty)
		return (1);
	return (0);
}

//is *.rt or not (1 - yes, 0 - no)
int	check_extension(char **av)
{
	char	*s_strrchr;

	s_strrchr = ft_strrchr(av[1], '/');
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 3, ".rt", 3) == 0 \
		&& ft_strlen(av[1]) == 3 && av[1][0] == '.')
		return (1);
	else if (ft_strncmp(av[1] + ft_strlen(av[1]) - 3, ".rt", 3) != 0)
		return (1);
	if (s_strrchr != NULL && s_strrchr[1] == '.' && ft_strlen(s_strrchr) == 4)
		return (1);
	return (0);
}
