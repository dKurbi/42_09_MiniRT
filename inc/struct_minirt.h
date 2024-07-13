/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_minirt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:31:29 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/13 21:45:15 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MINIRT_H
# define STRUCT_MINIRT_H

# include "./minirt.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bitspp;
	int		line_len;
	int		endian;
}	t_mlx;

//standard 3D vector
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

// 2D vector
typedef struct s_vector2
{
	double	x;
	double	y;
}	t_vector2;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_sphere
{
	t_vector		sp_center;
	double			sp_diam;
	t_rgb			sp_color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_vector		pl_point;
	t_vector		pl_normal;
	t_rgb			pl_color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vector			cy_center;
	t_vector			cy_axis;
	double				cy_diam;
	double				cy_height;
	t_rgb				cy_color;
	struct s_cylinder	*next;
}	t_cylinder;

//values for rendering CYLINDER
typedef struct s_cy_inter_val
{
	t_vector	half_height_vec;
	t_vector	cy_base;
	t_vector	cy_top;
	t_vector	delta_p;
	double		d_dot_v;
	double		delta_p_dot_v;
	t_vector	v_a;
	t_vector	v_b;
	double		a;
	double		b;
	double		c;
	double		discrim;
	double		sqrt_discrim;
	double		t1;
	double		t2;
	t_vector	hit1;
	t_vector	hit2;
	double		p1_dot_v;
	double		p2_dot_v;
}	t_cy_inter_val;

//quadratic formula structure
typedef struct s_quadr
{
	double		a;
	double		b;
	double		c;
	double		discrim;
	double		sqrt_discrim;
}	t_quadr;

//structure for rays
typedef struct s_ray
{
	t_vector	direction;
	t_vector	start;
	double		len;
}	t_ray;

//intersection struct
typedef struct s_intersec
{
	t_ray		ray;
	double		t1;
	double		t2;
	t_vector	hit1;
	t_vector	hit2;
	t_vector	n1;
	t_vector	n2;
	int			object;
	t_rgb		color;
}	t_intersec;

/*
	a_l_ = ambient lightning
	c_ = camera
	l_ = light
	sp_ = spheres
	pl_ = plane
	cy_ = cylinder
*/
typedef struct s_scene
{
	double		a_l_ratio;
	t_rgb		a_l_color;
	t_vector	c_pos;
	t_vector	c_dir;
	double		c_fov;
	t_vector	l_pos;
	double		l_bright;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	t_vector	v_up;
	t_vector	v_right;
}	t_scene;

//main structure: we add all to this t_rt
typedef struct s_rt
{
	t_mlx	rtmlx;
	int		fd;
	char	**av;
	int		ac;
	char	*line;
	char	**split;
	int		a_l_count;
	int		c_count;
	int		l_count;
	double	aspect_ratio;
	t_scene	scene;
}	t_rt;

#endif