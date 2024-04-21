/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:35:38 by iassambe          #+#    #+#             */
/*   Updated: 2023/08/17 21:03:51 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	get_ft_strlen(char *s);
char	*get_ft_strdup_modif(char *s1);
char	*get_ft_strjoin_modif(char *s1, char *s2);
char	*get_ft_strchr(char *s, int c);
char	*get_ft_substr_modif(char *s, unsigned int start, size_t len);
char	*get_free(char **strtofree);
char	*get_next_line(int fd);

#endif
