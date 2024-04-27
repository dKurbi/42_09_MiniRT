/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:35:34 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/27 17:41:30 by dkurcbar         ###   ########.fr       */
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
int		check_correct_value_fd(t_rt rt);
int		check_file(t_rt rt);

//check.c
int		check_if_empty_str(char *s);
int		check_if_empty_fd(t_rt rt, int fd);
int		check_extension(char **av);

//error.c
int		print_error(t_rt rt, char *s_err, int flag_free_mlx);
int		print_error_arg(t_rt rt, char *s_err, char *s_arg, int flag_free_mlx);

//event.c
int		event_mouse(int mouse, t_rt *rt);
int		event_key(int key, t_rt *rt);
int		event_destroy(t_rt *rt);

//free.c
char	*free_str(char **s);
void	free_mlx(t_mlx *rtmlx);
int		free_rt(t_rt *rt, int if_free_mlx);

//ft_atof.c
float	ft_atof(char *str);

//minirt.c

//struct.c
void	rtnew(t_rt *rt, int ac, char **av);
void	mlxnew(t_rt *rt);

//struct_scene.c
int		add_line_to_scene(t_rt rt, char *line);

//utils_mlx.c
void	pixel_put(t_rt rt, int x, int y, int color);

//utils.c
void	ft_close(int *fd);
int		skip_spaces(char *s, int i_provided);

#endif
