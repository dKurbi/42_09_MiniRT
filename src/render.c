/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:32:46 by diego             #+#    #+#             */
/*   Updated: 2024/07/15 14:29:37 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//inter[0] == plano, inter[1] == esfera, inter[2] == cilindro
t_intersec found_inter(t_ray ray, t_rt rt)
{
	t_intersec inter[3]; 
	t_intersec ret;
	int 		i;

	if (rt.scene.pl)
		inter[0] = found_inter_pl(ray, rt);
	if (rt.scene.sp)
		inter[1] = found_inter_sp(ray, rt);
	if (rt.scene.cy)
		inter[2] = found_inter_cy(ray, rt);
	i = 0;
	ret = inter[0];
	while (++i < 3)
	{
		if (ret.object == NO_INTER || (inter[i].object != NO_INTER && inter[i].t1 < ret.t1))
			ret = inter[i];
	}
	return (ret);
}

t_intersec found_inter_sp(t_ray ray, t_rt rt)
{
	t_sphere *sp;
	t_intersec inter;
	t_intersec temp;

	sp = rt.scene.sp;
	inter = inter_ray_sp(*sp, ray);
	if (inter.object == NO_INTER)
		inter.t1 = 0;
	sp = sp->next; 
	while (sp)
	{	
		temp = inter_ray_sp(*sp, ray);
		if (temp.object != NO_INTER &&  temp.t1 > inter.t1)
			inter = temp;
		sp = sp->next;
	}
	return (inter);
}

t_intersec found_inter_pl(t_ray ray, t_rt rt)
{
	t_plane *pl;
	t_intersec inter;
	t_intersec temp;

	pl = rt.scene.pl;
	inter = inter_ray_pl(*pl, ray);
	if (inter.object == NO_INTER)
		inter.t1 = 0;
	pl = pl->next; 
	while (pl)
	{	
		temp = inter_ray_pl(*pl, ray);
		if (temp.object != NO_INTER && temp.t1 < inter.t1)
			inter = temp;
		pl = pl->next;
	}
	return (inter);
}

t_intersec found_inter_cy(t_ray ray, t_rt rt)
{
	t_cylinder *cy;
	t_intersec inter;
	t_intersec temp;

	cy = rt.scene.cy;
	inter = inter_ray_cy(*cy, ray);
	if (inter.object == NO_INTER)
		inter.t1 = 0;
	cy = cy->next; 
	while (cy)
	{	
		temp = inter_ray_cy(*cy, ray);
		if (temp.object != NO_INTER && temp.t1 < inter.t1)
			inter = temp;
		cy = cy->next;
	}
	return (inter);
}

int	get_color_inter(t_intersec inter, t_rt rt)
{
	t_vector	l_dir;
	double		nxl;
	double		intensity;
	t_rgb		final_color;

	nxl = 0;
	intensity = rt.scene.a_l_ratio;
	if (inter.object == SPHERE || inter.object == CYLINDER)
	{
		l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.hit1));
    	nxl = v_dot(v_expand(l_dir, -1), inter.n1);
        if (nxl < 0)
            nxl = 0;
        intensity += rt.scene.l_bright * nxl;
    } 
	else if (inter.object == PLANE) 
	{
        l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.hit1));
        nxl = v_dot(l_dir, inter.n1);
        if (nxl < 0)
            nxl = 0;
        intensity += rt.scene.l_bright * nxl;
    } 

    if (intensity > 1.0)
        intensity = 1.0;

    final_color.r = (int)(inter.color.r * intensity);
    final_color.g = (int)(inter.color.g * intensity);
    final_color.b = (int)(inter.color.b * intensity);

    return color(final_color.r, final_color.g, final_color.b);
}