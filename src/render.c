/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:32:46 by diego             #+#    #+#             */
/*   Updated: 2024/06/10 16:27:11 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersec found_inter(t_ray ray, t_rt rt)
{
	t_intersec inter_sp;
	t_intersec inter_pl;
	static int global_print;

	inter_sp.object = NO_INTER;
	inter_pl.object = NO_INTER;

	if (rt.scene.sp)
		inter_sp = found_inter_sp(ray, rt);
	if (rt.scene.pl)
		inter_pl = found_inter_pl(ray, rt);
	if ((inter_pl.object == PLANE && inter_sp.object == SPHERE))
	{	
		if (global_print++ % 50 == 0)
		{
			printf("----------------Print Number = %d, ---- Hit Number = %d\n", (global_print - 1) / 50, global_print);
			print_v("Ray oringin ", ray.start);
			print_v("Ray direction ", ray.direction);
			printf("\nSphere\n ");
			printf("Sp t1 = %f, ",inter_sp.t1);	
			print_v("sphere hit ", inter_sp.h1);
			printf("\nPlane\n ");
			printf("Pl t1 = %f, ",inter_pl.t1);	
			print_v("Plane hit ", inter_pl.h1);
			printf("*********************************************\n\n");
			
		}
	}
	if ((inter_pl.object != NO_INTER && inter_sp.object == NO_INTER) || \
		(inter_pl.object == PLANE && inter_sp.object == SPHERE && \
		inter_pl.t1 < inter_sp.t1))
	{	
		//printf("plano\n");
		return (inter_pl);
	}
	return(inter_sp);
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
		if (temp.object != NO_INTER && temp.t1 < inter.t1)
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
/* 
int	get_color_inter(t_intersec inter, t_rt rt)
{
	t_vector	l_dir;
	double		nxl;
	
	nxl = 0;
	if (inter.object == SPHERE)
	{
		l_dir =v_normalized(v_rest(inter.h1, rt.scene.l_pos));
		nxl = -v_dot(l_dir, inter.n1);
		if (nxl < 0)
			nxl = 0;
	} else if (inter.object == PLANE)
	{
		nxl = 1;
	}
	//nxl = 1;
	return (color(inter.color.r * nxl, inter.color.g * nxl , inter.color.b * nxl ));
} */
/* int	get_color_inter(t_intersec inter, t_rt rt)
{
	t_vector	l_dir;
	double		nxl;
	double		intensity;
	t_rgb		final_color;

	nxl = 0;
	intensity = rt.scene.a_l_ratio; // Initialize intensity with ambient light ratio

	if (inter.object == SPHERE)
	{
		// Calculate the light direction
		l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.h1));
		// Calculate dot product between light direction and normal
		nxl = v_dot(l_dir, inter.n1);
		if (nxl < 0)
			nxl = 0;
		intensity += rt.scene.l_bright * nxl; // Add light intensity
	}
	else if (inter.object == PLANE)
	{
		// For planes, we assume the normal is constant, so light interaction is simpler
		l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.h1));
		nxl = v_dot(l_dir, inter.n1);
		if (nxl < 0)
			nxl = 0;
		intensity += rt.scene.l_bright * nxl; // Add light intensity
	}

	// Clamp intensity to a maximum of 1.0
	if (intensity > 1.0)
		intensity = 1.0;

	// Calculate final color based on the intensity
	final_color.r = (int)(inter.color.r * intensity);
	final_color.g = (int)(inter.color.g * intensity);
	final_color.b = (int)(inter.color.b * intensity);

	return color(final_color.r, final_color.g, final_color.b);
}

 */

int	get_color_inter(t_intersec inter, t_rt rt)
{
	t_vector	l_dir;
	double		nxl;
	double		intensity;
	t_rgb		final_color;

	nxl = 0;
	intensity = rt.scene.a_l_ratio;
	if (inter.object == SPHERE)
	{
		l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.h1));
    	nxl = v_dot(v_expand(l_dir, -1), inter.n1);
        if (nxl < 0)
            nxl = 0;
        intensity += rt.scene.l_bright * nxl;
    } else if (inter.object == PLANE) {
        l_dir = v_normalized(v_rest(rt.scene.l_pos, inter.h1));
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