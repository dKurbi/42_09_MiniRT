/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:45 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/08/20 02:58:34 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//create new intersection structure
t_intersec	new_intersec(void)
{
	t_intersec	new_intersec;

	new_intersec.object = NO_INTER;
	new_intersec.index = -1;
	new_intersec.t1 = -1;
	new_intersec.t2 = -1;
	return (new_intersec);
}

t_intersec	inter_ray_sp(t_sphere sp, t_ray ray)
{
	t_intersec		i_ret;
	t_quadr			val;

	i_ret.object = NO_INTER;
	i_ret.t1 = -1;
	val.a = v_lenght2(ray.direction);
	val.b = 2 * v_dot(ray.direction, v_rest(ray.start, sp.sp_center));
	val.c = v_lenght2(v_rest(ray.start, sp.sp_center)) - pow(sp.sp_diam / 2, 2);
	val.discrim = pow(val.b, 2) - 4 * val.a * val.c;
	if (val.discrim >= 0)
	{
		val.sqrt_discrim = sqrt(val.discrim);
		i_ret.color = sp.sp_color;
		i_ret.ray = ray;
		i_ret.t1 = (-val.b + val.sqrt_discrim) / (2 * val.a);
		i_ret.t2 = (-val.b - val.sqrt_discrim) / (2 * val.a);
		i_ret.t1 = choose_t(i_ret.t1, i_ret.t2);
		if (i_ret.t1 < 0)
			return (i_ret);
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
	i_ret.t1 = 0;
	dn = v_dot(ray.direction, pl.pl_normal);
	if (fabs(dn) > EPSILON)
	{
		i_ret.t1 = (v_dot(pl.pl_point, pl.pl_normal) - \
					v_dot(ray.start, pl.pl_normal)) / dn;
		if (i_ret.t1 < 0)
			return (i_ret);
		i_ret.color = pl.pl_color;
		i_ret.ray = ray;
		i_ret.hit1 = v_add(v_expand(ray.direction, i_ret.t1), ray.start);
		i_ret.n1 = pl.pl_normal;
		i_ret.object = PLANE;
		i_ret.t2 = 0;
	}
	return (i_ret);
}

//choose between t1 and t2
double	choose_t(double t1, double t2)
{
	if (t1 > 0 && t2 > 0)
	{
		if (t2 < t1)
			return (t2);
		return (t1);
	}
	if (t1 < 0 && t2 > 0)
		return (t2);
	if (t1 > 0 && t2 < 0)
		return (t1);
	return (-1);
}
