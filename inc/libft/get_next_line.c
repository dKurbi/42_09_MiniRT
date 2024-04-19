/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:34:45 by iassambe          #+#    #+#             */
/*   Updated: 2023/08/19 19:17:17 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_free(char **strtofree)
{
	if (*strtofree != NULL)
		free(*strtofree);
	*strtofree = NULL;
	return (NULL);
}

char	*get_edit_save(char *save)
{
	char	*newsave;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		return (get_free(&save));
	newsave = get_ft_substr_modif(save, i + 1, get_ft_strlen(save) - i + 1);
	free(save);
	save = NULL;
	if (newsave == NULL)
		return (NULL);
	return (newsave);
}

char	*get_make_arr(char *save)
{
	char	*newarr;
	int		i;

	if (save[0] == '\0')
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	newarr = get_ft_substr_modif(save, 0, i);
	if (newarr == NULL)
		return (NULL);
	return (newarr);
}

char	*get_reading_loop(int fd, char *save)
{
	char	*tempbuff;
	int		check;

	tempbuff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tempbuff == NULL)
		return (get_free(&save));
	check = 1;
	tempbuff[0] = '\0';
	while (check > 0 && !(get_ft_strchr(save, '\n')))
	{
		check = read(fd, tempbuff, BUFFER_SIZE);
		if (check < 0)
		{
			free(tempbuff);
			return (get_free(&save));
		}
		if (check > 0)
		{
			tempbuff[check] = '\0';
			save = get_ft_strjoin_modif(save, tempbuff);
		}
	}
	free(tempbuff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*arr;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (get_free(&save));
	save = get_reading_loop(fd, save);
	if (save == NULL)
		return (NULL);
	arr = get_make_arr(save);
	if (arr == NULL)
		return (get_free(&save));
	save = get_edit_save(save);
	return (arr);
}
