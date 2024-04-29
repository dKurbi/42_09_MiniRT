/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_minirt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:31:29 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/27 16:43:22 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MINIRT_H
# define STRUCT_MINIRT_H

# include "./minirt.h"

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bitspp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_rt
{
	t_mlx	rtmlx;
	int		fd;
	char	**av;
	int		ac;
	char	*line;
	char	**split;
	t_scene	scene;
}	t_rt;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_sphere
{
	t_vector		sp_center;
	float			sp_diam;
	t_rgb			sp_color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_vector		pl_point;
	t_vector		pl_normal;
	t_rgb			pl_color;
	struct s_plane	*next;
} t_plane;

typedef struct s_cylinder
{
	t_vector			cy_center;
	t_vector			cy_axis;
	float				cy_diam;
	float				cy_height;
	t_rgb				cy_color;
	struct s_cylinder	*next;
	
} t_cylinder;


// a_l = ambient lightning
// c_ = camera
// l_ = light
// sp = spheres
// pl = plane
// cy = cylinder
typedef struct s_scene
{
	float		a_l_ratio;
	t_rgb		a_l_color;
	t_vector	c_pos;
	t_vector	c_dir;
	float		c_fov;
	t_vector	l_pos;
	float		l_bright;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
} t_scene;


#endif