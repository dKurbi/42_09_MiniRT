/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:38:26 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/15 14:38:28 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersec	inter_ray_sp(t_sphere sp, t_ray ray)
{
	t_intersec	i_ret;
	t_cuadratica val;

	i_ret.object = NO_INTER;
	val.a = v_lenght2(ray.direction);
	val.b = 2 * v_dot(ray.direction, v_rest(ray.start, sp.sp_center));
	val.c = v_lenght2(v_rest(ray.start, sp.sp_center)) - pow(sp.sp_diam / 2, 2);
	val.discriminant = pow(val.b, 2) - 4 * val.a * val.c;
	if (val.discriminant >= 0)
	{
		val.sqrtDiscriminant = sqrt(val.discriminant);
		i_ret.color = sp.sp_color;
		i_ret.ray = ray;
		i_ret.t1 = (-val.b + val.sqrtDiscriminant) / (2 * val.a);
		i_ret.t2 = (-val.b - val.sqrtDiscriminant) / (2 * val.a);
		if (i_ret.t1 < 0 && i_ret.t2 < 0)
			return(i_ret);
		if (i_ret.t2 < i_ret.t1)
			i_ret.t2 =  i_ret.t1;
		i_ret.object = SPHERE;
		i_ret.hit1 = v_add(v_expand(ray.direction, i_ret.t1), ray.start);
		i_ret.n1 = v_normalized(v_rest(i_ret.hit1, sp.sp_center));

	}
	return (i_ret);
}

t_intersec	inter_ray_pl(t_plane pl, t_ray ray)
{
	t_intersec	i_ret;
	double		dn;

	i_ret.object = NO_INTER;
	dn = v_dot(v_normalized(ray.direction), v_normalized(pl.pl_normal));
	if (fabs(dn) > EPSILON)
	{
		i_ret.t1 = (v_dot(pl.pl_point, pl.pl_normal) - \
					v_dot(ray.start, pl.pl_normal)) / dn;
		i_ret.color = pl.pl_color;
		i_ret.ray = ray;
		i_ret.hit1 = v_add(v_expand(ray.direction, i_ret.t1), ray.start);
		i_ret.n1 = v_normalized(pl.pl_normal);
		i_ret.object = PLANE;
		if (i_ret.t1 < 0)
			i_ret.object = NO_INTER;
	}
	return (i_ret);
}
