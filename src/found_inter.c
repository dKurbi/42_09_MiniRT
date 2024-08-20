/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:32:46 by diego             #+#    #+#             */
/*   Updated: 2024/08/20 02:55:55 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//inter[0] == plane, inter[1] == sphere, inter[2] == cylinder
t_intersec	found_inter(t_ray ray, t_rt rt, int ob_avoid, int index_avoid)
{
	t_intersec	inter[4];
	t_intersec	ret;
	int			i;

	i = -1;
	while (++i < 4)
		inter[i] = new_intersec();
	if (rt.scene.pl)
		inter[0] = found_inter_pl(ray, rt, ob_avoid, index_avoid);
	if (rt.scene.sp)
		inter[1] = found_inter_sp(ray, rt, ob_avoid, index_avoid);
	if (rt.scene.cy)
	{
		inter[2] = found_inter_cy_body(ray, rt, ob_avoid, index_avoid);
		inter[3] = found_inter_cy_base(ray, rt, ob_avoid, index_avoid);
	}
	i = 0;
	ret = inter[0];
	while (++i < 4)
	{
		if (ret.object == NO_INTER || \
			(inter[i].object > NO_INTER && inter[i].t1 < ret.t1))
			ret = inter[i];
	}
	return (ret);
}

//if indersection in sphere
t_intersec	found_inter_sp(t_ray ray, t_rt rt, int ob_avoid, int index_avoid)
{
	t_sphere	*sp;
	t_intersec	inter;
	t_intersec	temp;
	int			index;

	sp = rt.scene.sp;
	index = 0;
	inter = new_intersec();
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

//if indersection in plane
t_intersec	found_inter_pl(t_ray ray, t_rt rt, int ob_avoid, int index_avoid)
{
	t_plane		*pl;
	t_intersec	inter;
	t_intersec	temp;
	int			index;

	pl = rt.scene.pl;
	index = 0;
	inter = new_intersec();
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

t_intersec	found_inter_cy_body(t_ray ray, t_rt rt, int ob_avoid, \
	int index_avoid)
{
	t_cylinder	*cy;
	t_intersec	inter;
	t_intersec	temp;
	int			index;

	cy = rt.scene.cy;
	index = 0;
	inter = new_intersec();
	while (cy)
	{
		if (!(ob_avoid == CYLINDER && index == index_avoid))
		{
			temp = inter_ray_cy_body(*cy, ray);
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

t_intersec	found_inter_cy_base(t_ray ray, t_rt rt, int ob_avoid, \
	int index_avoid)
{
	t_cylinder	*cy;
	t_intersec	inter;
	t_intersec	temp;
	int			index;

	cy = rt.scene.cy;
	index = 0;
	inter = new_intersec();
	while (cy)
	{
		if (!(ob_avoid == T_CYLINDER && index == index_avoid))
		{
			temp = inter_ray_cy_bases(*cy, ray);
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
