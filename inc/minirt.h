/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:35:34 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/30 16:46:16 by dkurcbar         ###   ########.fr       */
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

//add_scene_capital.c
int			add_ambient_light(t_rt *rt, char *line);
int			add_camera(t_rt *rt, char *line);
int			add_light(t_rt *rt, char *line);
void 		add_light_as_sphere(t_rt *rt);

//add_scene_lower_second.c
int			add_sp_second_part(t_rt *rt, char *line, int i, t_sphere *new_sp);
int			add_pl_second_part(t_rt *rt, char *line, int i, t_plane *new_pl);
int			add_cy_second_part(t_rt *rt, char *line, int i, t_cylinder *new_cy);

//add_scene_lower.c
int			add_sphere(t_rt *rt, char *line);
int			add_plane(t_rt *rt, char *line);
int			add_cylinder(t_rt *rt, char *line);

//add_structure_figure.c
void		add_sphere_lst(t_rt *rt, t_sphere *new_sphere);
void		add_plane_lst(t_rt *rt, t_plane *new_plane);
void		add_cylinder_lst(t_rt *rt, t_cylinder *new_cyl);

//check.c
int			check_if_empty_str(char *s);
int			check_if_empty_fd(t_rt rt, int fd);
int			check_extension(char **av);

//check_file.c
int			rgb_limit(int r, int g, int b);
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
int			print_ocurred_line(int number);

//event.c
int			event_mouse(int mouse, t_rt *rt);
int			event_key(int key, t_rt *rt);
int			event_destroy(t_rt *rt);

//free.c
char		*free_str(char **s);
void		free_mlx(t_mlx *rtmlx);
int			free_rt(t_rt *rt, int if_free_mlx);

//free_struct_lst.c
char		*free_double_str(char ***s);
void		free_sphere(t_sphere **sphere);
void		free_plane(t_plane **plane);
void		free_cylinder(t_cylinder **cylinder);

//ft_atof.c
double		ft_atof(char *str);

//init_cam.c
void		init_cam(t_rt *rt);

//intersection.c
t_intersec	inter_ray_sp(t_sphere sp, t_ray ray);
t_intersec	inter_ray_pl(t_plane pl, t_ray ray);
double		choose_t(double t1, double t2);

//intersection_cy.c
t_intersec	inter_ray_cy_body(t_cylinder cy, t_ray ray);
t_intersec	inter_ray_cy_base(t_cylinder cy, t_ray ray);
t_intersec	inter_ray_base_cy(t_cylinder cy, t_ray ray, \
	t_cy_inter_values val, int type);

//intersection_cy_calc.c
t_cy_inter_values	calc_inter_values(t_cylinder cy, t_ray ray);
t_vector			calculate_normal_cy(t_cylinder cy, t_vector hit);



//maths_others.c
double		get_radian(double angle);
double		get_degree(double radian);
double		absolute(double num);

//maths_vector_2.c
double		v_lenght2(t_vector vector);
double		v_lenght(t_vector vector);
t_vector	v_normalized(t_vector vector);
t_vector 	v_new(double x, double y, double z);

//maths_vector.c
t_vector	v_expand(t_vector v, double k);
t_vector	v_add(t_vector v1, t_vector v2);
t_vector	v_rest(t_vector v1, t_vector v2);
double		v_dot(t_vector v1, t_vector v2);
t_vector	v_cross(t_vector v1, t_vector v2);

//minirt.c
void		raytracing(t_rt *rt);

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
int			color(int r, int g, int b);

//utils_check_2.c
int			empty_after_line(char *line, int i_provide);
int			check_is_a_rgb_create(char *str, int *i, int i_copy, t_rgb *color);
int			skip_space_check_not_enough_values(char *line, int *i);

//utils_check.c
int			check_is_a_vector_loop(char *str, int i_c, int *point, int *coma);
int			check_is_a_vector_add(char *str, int *i, t_vector *vec, int i_cop);
int			check_is_a_float_first_check(char *str, int *i, int *end);
int			check_is_a_float_add(char *str, int *i, int end, double *fl);

//utils.c
void		ft_close(int *fd);
int			skip_spaces(char *s, int i_provided);
int			if_space(char c);
int			len_split(char **split);

//print.c
void		print_v(char *name, t_vector v);
void		print_rgb(char *name, t_rgb rgb);
void		print_plane(char *name, t_plane p);
void		print_sphere(char *name, t_sphere s);
void		print_scene(t_scene s);
void		print_cylinder(char *name, t_cylinder c);

//rotation.c 
t_vector	rotation_x(t_vector v, double ang);
t_vector	rotation_y(t_vector v, double ang);
t_vector2	calc_ang_rot(int x, int y, double fov, double aspect_ratio);
t_vector	rotation_axis(t_vector v, t_vector u, double ang);
void		calc_up_right_vector(t_rt *rt);


//ray_and_pixel.c
t_ray	make_ray(t_vector2 point, t_rt rt);

//found_inter.c
t_intersec	found_inter(t_ray ray, t_rt rt, int ob_avoid, int index_avoid);
t_intersec	found_inter_sp(t_ray ray, t_rt rt, int ob_avoid, int index_avoid);
t_intersec	found_inter_pl(t_ray ray, t_rt rt, int ob_avoid, int index_avoid);
t_intersec 	found_inter_cy_body(t_ray ray, t_rt rt, int ob_avoid, int index_avoid);
t_intersec	new_intersec(void);
t_intersec	found_inter_cy_base(t_ray ray, t_rt rt, int ob_avoid, int index_avoid);

//get_color.c
int			get_color_inter(t_intersec inter, t_rt rt);
int			is_shadow(t_intersec inter, t_rt rt);
int			is_plane_in_the_middle(t_intersec inter, t_rt rt);

//cam_moves.c
void	cam_spin(t_rt *rt, double ang);
void	cam_m_h(t_rt *rt, double ang);
void	cam_m_v(t_rt *rt, double ang);
void	cam_m_fwd(t_rt *rt, int distance);

//light_change.c
void 	amb_light_more_bright (t_rt *rt);
void 	amb_light_less_bright (t_rt *rt);

//zoom.c
int		zoom_in(t_rt *rt);
int		zoom_out(t_rt *rt);

#endif
