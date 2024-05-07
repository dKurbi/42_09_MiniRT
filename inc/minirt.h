/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:35:34 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/07 03:07:44 by iassambe         ###   ########.fr       */
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

//add_scene_lower.c
int			add_sphere(t_rt *rt, char *line);
int			add_plane(t_rt *rt, char *line);
int			add_cylinder(t_rt *rt, char *line);

//add_scene_capital.c
int			add_ambient_light(t_rt *rt, char *line);
int			add_camera(t_rt *rt, char *line);
int			add_light(t_rt *rt, char *line);

//add_structure_figure.c
void		add_sphere_lst(t_rt *rt, t_sphere *new_sphere);
void		add_plane_lst(t_rt *rt, t_plane *new_plane);
void		add_cylinder_lst(t_rt *rt, t_cylinder *new_cyl);


//check.c
int			check_if_empty_str(char *s);
int			check_if_empty_fd(t_rt rt, int fd);
int			check_extension(char **av);

//check_file.c
int			add_line_to_scene(t_rt *rt, char *line);
int			check_save_value(t_rt *rt);
int			check_file(t_rt rt);

//check_str_number.c
int			check_is_a_vector(char *str, int *i, t_vector *vector);
int			check_is_a_float(char *str, int *i, double *fl);
int			check_is_a_rgb(char *line, int *i, t_rgb *color);
int			check_is_a_vector_range(char *line, int *i, t_vector *vec);

//error.c
int			print_error(t_rt rt, char *s_err, int flag_mlx);
int			print_error_arg(t_rt rt, char *s_err, char *s_arg, int flag_mlx);

//event.c
int			event_mouse(int mouse, t_rt *rt);
int			event_key(int key, t_rt *rt);
int			event_destroy(t_rt *rt);

//free.c
char		*free_str(char **s);
char		*free_double_str(char ***s);
void		free_mlx(t_mlx *rtmlx);
int			free_rt(t_rt *rt, int if_free_mlx);

//free_struct_lst.c
void		free_sphere(t_sphere **sphere);
void		free_plane(t_plane **plane);
void		free_cylinder(t_cylinder **cylinder);

//ft_atof.c
double		ft_atof(char *str);

//minirt.c

//struct.c
void		rtnew(t_rt *rt, int ac, char **av);
void		mlxnew(t_rt *rt);
t_sphere	*init_sphere(void);
t_plane		*init_plane(void);
t_cylinder	*init_cylinder(void);

//struct_scene.c
int			add_line_to_scene(t_rt *rt, char *line);

//utils_mlx.c
void		pixel_put(t_rt rt, int x, int y, int color);

//utils_check.c
int			empty_after_line(char *line, int i_provide);
int			rgb_limit(int r, int g, int b);

//utils.c
void		ft_close(int *fd);
int			skip_spaces(char *s, int i_provided);
int			if_space(char c);
int			len_split(char **split);

#endif
