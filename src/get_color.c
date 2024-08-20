/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:55:16 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/08/20 02:57:16 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//grab final color in int
int	get_color_inter_final_col(t_intersec inter, t_rt rt, double intensity)
{
	t_rgb	fin_col;

	fin_col.r = (int)(inter.color.r * intensity * rt.scene.a_l_color.r / 255);
	fin_col.g = (int)(inter.color.g * intensity * rt.scene.a_l_color.g / 255);
	fin_col.b = (int)(inter.color.b * intensity * rt.scene.a_l_color. b / 255);
	return (color(fin_col.r, fin_col.g, fin_col.b));
}

//get the final color for printing on screen
int	get_color_inter(t_intersec inter, t_rt rt)
{
	t_vector	l_dir;
	double		nxl;
	double		intensity;

	nxl = 0;
	intensity = rt.scene.a_l_ratio * 0.8;
	if (!is_shadow(inter, rt))
	{
		if (inter.object != NO_INTER)
		{
			l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.hit1));
			nxl = v_dot(l_dir, inter.n1);
			if (inter.object == PLANE || inter.object == T_CYLINDER)
				nxl = fabs(nxl);
			if (nxl < 0)
				nxl = 0;
			intensity += rt.scene.l_bright * nxl;
		}
		if (intensity > 1.0)
			intensity = 1.0;
	}
	return (get_color_inter_final_col(inter, rt, intensity));
}

//1 shadow, 0 no shadow
int	is_shadow(t_intersec inter, t_rt rt)
{
	t_ray		ray;
	t_intersec	shadow;
	double		norm2_l_h;
	t_vector	l_h;

	ray.start = inter.hit1;
	l_h = v_rest(rt.scene.l_pos, inter.hit1);
	ray.direction = v_normalized(l_h);
	if (inter.object == PLANE)
		if (is_plane_in_the_middle(inter, rt))
			return (1);
	shadow = found_inter(ray, rt, inter.object, inter.index);
	if (inter.object == shadow.object && \
		shadow.t1 < EPSILON)
		return (0);
	norm2_l_h = v_lenght2(l_h);
	if (shadow.object == NO_INTER || norm2_l_h <= pow(shadow.t1, 2))
		return (0);
	return (1);
}

//1 is a plane inter light and camera
int	is_plane_in_the_middle(t_intersec inter, t_rt rt)
{
	t_intersec	inter2;
	t_plane		*plane;
	t_ray		ray;
	int			i;

	ray.direction = v_normalized(v_rest (rt.scene.l_pos, rt.scene.c_pos));
	ray.start = rt.scene.c_pos;
	plane = rt.scene.pl;
	i = 0;
	while (i++ < inter.index)
		plane = plane->next;
	inter2 = inter_ray_pl(*plane, ray);
	if (inter2.object == NO_INTER)
		return (0);
	if (v_lenght2(v_rest(rt.scene.l_pos, rt.scene.c_pos)) > \
		v_lenght2(v_rest(inter2.hit1, rt.scene.c_pos)))
		return (1);
	return (0);
}
