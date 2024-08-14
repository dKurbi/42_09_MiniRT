/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cam_is_inside.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:56:27 by diego             #+#    #+#             */
/*   Updated: 2024/08/14 16:22:23 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	check_cam_is_inside(t_rt rt)
{
	return (is_in_sp_lst(rt) || is_in_pl_lst(rt) || is_in_cy_lst(rt));
}

int	is_in_sp_lst(t_rt rt)
{
	t_sphere	*sp;

	sp = rt.scene.sp;
	while (sp)
	{
		if (is_inside_sp(*sp, rt))
			return (1);
		sp = sp->next;
	}
	return (0);
}

int	is_in_pl_lst(t_rt rt)
{
	t_plane	*pl;

	pl = rt.scene.pl;
	while (pl)
	{
		if (is_inside_pl(*pl, rt))
			return (1);
		pl = pl->next;
	}
	return (0);
}

int	is_in_cy_lst(t_rt rt)
{
	t_cylinder	*cy;

	cy = rt.scene.cy;
	while (cy)
	{
		if (is_inside_cy(*cy, rt))
			return (1);
		cy = cy->next;
	}
	return (0);
}
