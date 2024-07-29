/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:55:16 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/07/29 14:07:05 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	get_color_inter(t_intersec inter, t_rt rt)
{
	t_vector	l_dir;
	double		nxl;
	double		intensity;
	t_rgb		final_color;

	nxl = 0;
	intensity = rt.scene.a_l_ratio * 0.8;
	if (inter.object == SPHERE && inter.index == 0)
		return (color(255,255,255));
	if (!is_shadow(inter, rt))
	{
		if (inter.object == SPHERE || inter.object == CYLINDER)
		{
			l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.hit1));
			nxl = v_dot(l_dir, inter.n1);
			if (nxl < 0)
				nxl = 0;
			intensity += rt.scene.l_bright * nxl;
		}
		else if (inter.object == PLANE)
		{
			l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.hit1));
			nxl = v_dot(l_dir, inter.n1);
			if (nxl < 0)
				nxl = -nxl;
			intensity += rt.scene.l_bright * nxl;
		}
		if (intensity > 1.0)
			intensity = 1.0;
	}
	final_color.r = (int)(inter.color.r * intensity);
	final_color.g = (int)(inter.color.g * intensity);
	final_color.b = (int)(inter.color.b * intensity);
	return (color(final_color.r, final_color.g, final_color.b));
}

//1 shadow, 0 no shadow
int	is_shadow(t_intersec inter, t_rt rt)
{
	t_ray		ray;
	t_intersec	shadow;
	double		norm_l_h;
	t_vector	l_h;
	
	ray.start = inter.hit1;
	l_h =  v_rest(rt.scene.l_pos, inter.hit1);
	ray.direction = v_normalized(l_h);
	shadow = found_inter(ray, rt, inter.object, inter.index);
	norm_l_h =  v_lenght2(l_h);
	if (shadow.object == NO_INTER || norm_l_h < pow(shadow.t1, 2) || \
			(shadow.object == SPHERE && inter.index == 0))
		return (0);
	return (1);
	
}
