/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_inter _shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:32:46 by diego             #+#    #+#             */
/*   Updated: 2024/07/24 01:00:35 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//inter[0] == plano, inter[1] == esfera, inter[2] == cilindro
t_intersec	found_inter(t_ray ray, t_rt rt, int ob_avoid, int index_aboid)
{
	t_intersec	inter[3];
	t_intersec	ret;
	int			i;

	i = -1;
	while (++i < 3)
		inter[i].object = NO_INTER;
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
		if (ret.object == NO_INTER || \
			(inter[i].object > NO_INTER && inter[i].t1 < ret.t1))
			ret = inter[i];
	}
	if (ret.object != NO_INTER)
		printf("objeto = %d, index = %d\n", ret.object, ret.index);
	return (ret);
}


t_intersec	found_inter_cy(t_ray ray, t_rt rt, int)
{
	t_cylinder	*cy;
	t_intersec	inter;
	t_intersec	temp;
	int			index;

	cy = rt.scene.cy;
	index = 0;
	inter.index = -1;
	inter.object = NO_INTER;
	while (cy)
	{
		temp = inter_ray_cy(*cy, ray);
		if (inter.object == NO_INTER || \
			(temp.object != NO_INTER && temp.t1 < inter.t1))
		{
			inter = temp;
			inter.index = index;
		}
		cy = cy->next;
		index++;
	}
	return (inter);
}

t_intersec	found_inter_sp(t_ray ray, t_rt rt)
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
			
		temp = inter_ray_sp(*sp, ray);
		if (inter.object == NO_INTER || \
			(temp.object != NO_INTER && temp.t1 < inter.t1))
		{
			inter = temp;
			inter.index = index;
		}
		sp = sp->next;
		index++;
	}
	return (inter);
}

t_intersec	found_inter_pl(t_ray ray, t_rt rt)
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
		temp = inter_ray_pl(*pl, ray);
		if (inter.object == NO_INTER || \
			(temp.object != NO_INTER && temp.t1 < inter.t1))
		{
			inter = temp;
			inter.index = index;
		}
		pl = pl->next;
		index++;
	}
	return (inter);
}




