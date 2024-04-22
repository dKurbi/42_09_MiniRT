/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:33:48 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/22 20:47:50 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_if_empty_str(char *s)
{
	size_t	i;
	int		count_nl;

	if (ft_strlen(s) == 0 || s[0] == '\0')
		return (1);
	count_nl = 0;
	i = 0;
	while (s && s[i] && (s[i] == SPACE || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

int	check_if_empty_fd(int fd, char *s)
{
	int	count_lines;
	int	count_empty;

	count_lines = 0;
	count_empty = 0;
	while (s != NULL)
	{
		if (check_if_empty_str(s))
			count_empty++;
		free_str(&s);
		count_lines++;
		s = get_next_line(fd);
	}
	ft_close(&fd);
	free_str(&s);
	if (count_lines == count_empty)
	{
		printf("emptao\n");
		return (1);
	}
	return (0);
}

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

int	check_file(t_rt rt)
{
	rt.fd = open(rt.av[1], O_RDONLY);
	if (rt.fd < 0)
	{
		(void)write(STDERR_FILENO, STR_MINIRT, ft_strlen(STR_MINIRT));
		perror(rt.av[1]);
		exit(free_rt(&rt));
	}
	if (check_extension(rt.av) > 0)
		return (print_error_arg(rt, ERR_EXTENSION, rt.av[1], ERROR));
	rt.line = get_next_line(rt.fd);
	if (!rt.line || check_if_empty_fd(rt.fd, rt.line) > 0)
		return (print_error_arg(rt, ERR_EMPTY, rt.av[1], ERROR));
	rt.fd = open(rt.av[1], O_RDONLY);
	ft_close(&rt.fd);
	return (0);
}
