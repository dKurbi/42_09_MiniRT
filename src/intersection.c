/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:38:26 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/26 16:56:55 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersec	inter_ray_sp(t_sphere sp, t_ray ray)
{
	t_intersec	i_ret;
	double		a;
	double		b;
	double		c;
	double		det;

	i_ret.object = NO_INTER;
	a = v_lenght2(ray.direction);
	b = 2 * v_dot(ray.direction, v_rest(ray.start, sp.sp_center));
	c = v_lenght2(v_rest(ray.start, sp.sp_center)) - pow(sp.sp_diam / 2, 2);
	det = pow(b, 2) - 4 * a * c;
	if (det >= 0)
	{
		i_ret.color = sp.sp_color;
		i_ret.object = SPHERE;
		i_ret.ray = ray;
		i_ret.t1 = (-b + det) / (2 * a);
		i_ret.t2 = (-b - det) / (2 * a);
	}
	return (i_ret);
}

t_intersec	inter_ray_pl(t_plane pl, t_ray ray)
{
	t_intersec	i_ret;
	double		dn;

	i_ret.object = NO_INTER;
	dn = v_dot(ray.direction, pl.pl_normal);
	if (dn != 0)
	{
		i_ret.t1 = (v_dot(pl.pl_point, pl.pl_normal) - v_dot(ray.start, pl.pl_normal)) / dn;
		i_ret.color = pl.pl_color;
		i_ret.ray = ray;
		i_ret.object = PLANE;
	}
	return (i_ret);
}
