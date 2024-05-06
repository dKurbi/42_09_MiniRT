/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_struct_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 03:34:49 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/06 04:12:01 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	add_sphere_lst(t_rt *rt, t_sphere *new_sphere)
{
	t_sphere	*lst_sphere;

	if (rt->scene.sp == NULL)
		rt->scene.sp = new_sphere;
	else
	{
		lst_sphere = rt->scene.sp;
		while (lst_sphere->next)
			lst_sphere = lst_sphere->next;
		lst_sphere->next = new_sphere;
	}
}

void	add_plane_lst(t_rt *rt, t_plane *new_plane)
{
	t_plane	*lst_plane;

	if (rt->scene.pl == NULL)
		rt->scene.pl = new_plane;
	else
	{
		lst_plane = rt->scene.pl;
		while (lst_plane->next)
			lst_plane = lst_plane->next;
		lst_plane->next = new_plane;
	}
}

void	add_cylinder_lst(t_rt *rt, t_cylinder *new_cyl)
{
	t_cylinder	*lst_cylinder;

	if (rt->scene.cy == NULL)
		rt->scene.cy = new_cyl;
	else
	{
		lst_cylinder = rt->scene.cy;
		while (lst_cylinder->next)
			lst_cylinder = lst_cylinder->next;
		lst_cylinder->next = new_cyl;
	}
}
