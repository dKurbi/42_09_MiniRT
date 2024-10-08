/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:54:44 by diego             #+#    #+#             */
/*   Updated: 2024/08/17 20:47:07 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	print_v(char *name, t_vector v)
{
	printf("%s: x: %f, y: %f, z: %f\n", name, v.x, v.y, v.z);
}

void	print_rgb(char *name, t_rgb rgb)
{
	printf("%s: R:%d G:%d B:%d\n", name, rgb.r, rgb.g, rgb.b);
}

void	print_plane(char *name, t_plane p)
{
	printf("%s\n", name);
	print_v("Point", p.pl_point);
	print_v("Normal", p.pl_normal);
	print_rgb("Color", p.pl_color);
}

void	print_sphere(char *name, t_sphere s)
{
	printf("%s\n", name);
	print_v("Center", s.sp_center);
	printf("Diam: %f\n", s.sp_diam);
	print_rgb("Color", s.sp_color);
}

void	print_cylinder(char *name, t_cylinder c)
{
	printf("%s\n", name);
	print_v("Center", c.cy_center);
	print_v("Axis", c.cy_axis);
	printf("Diam: %f\n", c.cy_diam);
	printf("Height: %f\n", c.cy_height);
	print_rgb("Color", c.cy_color);
}

void	print_scene_figures(t_sphere *sp, t_plane *pl, \
	t_cylinder *cy, int i)
{
	if (sp != NULL)
		printf("\nLIST OF SPHERES\n");
	while (sp != NULL)
	{
		printf("%d: ", i++);
		print_sphere("Sphere", *sp);
		sp = sp->next;
	}
	i = 0;
	if (pl != NULL)
		printf("\nLIST OF PLANES\n");
	while (pl != NULL)
	{
		printf("%d: ", i++);
		print_plane("Plane", *pl);
		pl = pl->next;
	}
	i = 0;
	if (cy != NULL)
		printf("\nLIST OF CYLINDER\n");
	while (cy != NULL)
	{
		printf("%d: ", i++);
		print_cylinder("Cylinder", *cy);
		cy = cy->next;
	}
}

void	print_scene(t_scene s)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	int			i; 

//eliminar
	printf("--------SCENE-------\n");
	printf("\nAMBIENT\n");
	printf("Ratio: %f\n", s.a_l_ratio);
	print_rgb("Color", s.a_l_color);
	printf("\nCAMERA\n");
	print_v("Camara position", s.c_pos);
	print_v("Camara direction", s.c_dir);
	printf("len Camara direction: %f len2: %f\n", v_lenght(s.c_dir), \
		v_lenght2(s.c_dir));
	printf("Camera FOV: %f rad, FOV: %dº\n", s.c_fov, (int)(s.c_fov * 180 \
		 / M_PI));
	printf("\nLIGHT\n");
	print_v("Light Position", s.l_pos);
	printf("Light bright: %f\n", s.l_bright);
	sp = s.sp;
	pl = s.pl;
	i = 0;
	cy = s.cy;
	print_scene_figures(sp, pl, cy, i); 
	print_v("vector up", s.v_up);
	print_v("vector right", s.v_right);
}
