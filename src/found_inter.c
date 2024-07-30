/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:32:46 by diego             #+#    #+#             */
/*   Updated: 2024/07/30 16:21:26 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//inter[0] == plano, inter[1] == esfera, inter[2] == cilindro
t_intersec	found_inter(t_ray ray, t_rt rt, int ob_avoid, int index_avoid)
{
	t_intersec	inter[3];
	t_intersec	ret;
	int			i;

	i = -1;
	while (++i < 3)
	{
		inter[i].object = NO_INTER;
		inter[i].index = 0; 
	}
	if (rt.scene.pl)
		inter[0] = found_inter_pl(ray, rt, ob_avoid, index_avoid);
	if (rt.scene.sp)
		inter[1] = found_inter_sp(ray, rt, ob_avoid, index_avoid);
	if (rt.scene.cy)
		inter[2] = found_inter_cy(ray, rt, ob_avoid, index_avoid);
	i = 0;
	ret = inter[0];
	while (++i < 3)
	{
		if (ret.object == NO_INTER || \
			(inter[i].object > NO_INTER && inter[i].t1 < ret.t1))
			ret = inter[i];
	}
	//if (ret.object != NO_INTER)
	//	printf("objeto = %d, index = %d\n", ret.object, ret.index);
	return (ret);
}

t_intersec	found_inter_sp(t_ray ray, t_rt rt, int ob_avoid, int index_avoid)
{
	t_sphere	*sp;
	t_intersec	inter;
	t_intersec	temp;
	int			index;

	sp = rt.scene.sp;
	index = 0;
	inter.index = -1;
	inter.object = NO_INTER;
	while (sp)
	{
		if (!(ob_avoid == SPHERE && index == index_avoid))
		{
			temp = inter_ray_sp(*sp, ray);
			if (inter.object == NO_INTER || \
				(temp.object != NO_INTER && temp.t1 < inter.t1))
			{
				inter = temp;
				inter.index = index;
			}
		}
		sp = sp->next;
		index++;
	}
	return (inter);
}

t_intersec	found_inter_pl(t_ray ray, t_rt rt, int ob_avoid, int index_avoid)
{
	t_plane		*pl;
	t_intersec	inter;
	t_intersec	temp;
	int			index;


	pl = rt.scene.pl;
	index = 0;
	inter.index = -1;
	inter.object = NO_INTER;
	while (pl)
	{
		if (!(ob_avoid == PLANE && index == index_avoid))
		{
			temp = inter_ray_pl(*pl, ray);
			if (inter.object == NO_INTER || \
				(temp.object != NO_INTER && temp.t1 < inter.t1))
			{
				inter = temp;
				inter.index = index;
			}
		}
		pl = pl->next;
		index++;
	}
	return (inter);
}

t_intersec	found_inter_cy(t_ray ray, t_rt rt, int ob_avoid, int index_avoid)
{
	t_cylinder	*cy;
	t_intersec	inter;
	t_intersec	temp;
	int			index;

	cy = rt.scene.cy;
	index = 0;
	inter.index = -1;
	inter.object = NO_INTER;
	inter.index = -1;
	while (cy)
	{
		if (!(ob_avoid >= CYLINDER && index == index_avoid))
		{
			temp = inter_ray_cy(*cy, ray);
			if (inter.object == NO_INTER || \
				(temp.object != NO_INTER && temp.t1 < inter.t1))
			{
				inter = temp;
				inter.index = index;
			}
		}
		cy = cy->next;
		index++;
	}
	return (inter);
}

