/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:35:34 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 17:33:09 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

# include "./struct_minirt.h"
# include "./define_minirt.h"
# include "./libft/libft.h"

# ifdef __linux__
#  include "./minilibx-linux/mlx.h"
# else
#  include "./minilibx-mac/mlx.h"
# endif

//check_file.c
int		check_if_empty_str(char *s);
int		check_if_empty_fd(int fd, t_rt rt);
int		check_file(t_rt rt);

//error.c
int		print_error(t_rt rt, char *s_err, int mlx_free);
int		print_error_arg(t_rt rt, char *s_err, char *s_arg, int mlx_free);

//event.c
int		event_key(int key, t_rt *rt);
int		event_destroy(t_rt *rt);

//free.c
char	*free_str(char **s);
void	free_mlx(t_mlx *rtmlx);
int		free_rt(t_rt *rt, int if_free_mlx);

//minirt.c

//struct.c
void	rtnew(t_rt *rt, int ac, char **av);
void	mlxnew(t_rt *rt);

//utils_mlx.c
void	pixel_put(t_rt rt, int x, int y, int color);

//utils.c
void	ft_close(int *fd);

#endif
