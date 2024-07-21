/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:38:26 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/21 07:32:15 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersec	inter_ray_base_cy(t_cylinder cy, t_ray ray, t_cy_inter_values val)
{
	float		t_base;
	t_intersec	i_ret;
	t_vector	hit_base;
	t_vector	base_to_hit;

	i_ret.object = NO_INTER;
	t_base = v_dot(v_rest(val.cylBase, ray.start), cy.cy_axis) / \
		v_dot(ray.direction, cy.cy_axis);
	hit_base = v_add(ray.start, v_expand(ray.direction, t_base));
	base_to_hit = v_rest(hit_base, val.cylBase);
	if (v_dot(base_to_hit, base_to_hit) <= pow(cy.cy_diam / 2, 2) \
		&& t_base > 0)
	{
		i_ret.t1 = t_base;
		if (i_ret.t1 < 0)
			return (i_ret);
		i_ret.object = CYLINDER;
		i_ret.hit1 = hit_base;
		i_ret.color = cy.cy_color;
		i_ret.n1 = cy.cy_axis;
	}
	return (i_ret);
}

t_intersec	inter_ray_top_cy(t_cylinder cy, t_ray ray, t_cy_inter_values val)
{
	t_intersec	i_ret;
	t_vector	top_normal;
	float		t_top;
	t_vector	hit_top;
	t_vector	top_to_hit;

	top_normal = v_expand(cy.cy_axis, -1);
	i_ret.object = NO_INTER;
	t_top = v_dot(v_rest(val.cylTop, ray.start), top_normal) / \
		v_dot(ray.direction, top_normal);
	hit_top = v_add(ray.start, v_expand(ray.direction, t_top));
	top_to_hit = v_rest(hit_top, val.cylTop);
	if (v_dot(top_to_hit, top_to_hit) <= pow(cy.cy_diam / 2, 2) && t_top > 0)
	{
		i_ret.t1 = t_top;
		if (i_ret.t1 < 0)
			return (i_ret);
		i_ret.object = CYLINDER;
		i_ret.hit1 = hit_top;
		i_ret.color = cy.cy_color;
		i_ret.n1 = top_normal;
	}
	return (i_ret);
}

// Intersección con la tapa y la base del cilindro
t_intersec	inter_ray_t_b_cy(t_cylinder cy, t_ray ray, t_cy_inter_values val)
{
	t_intersec	i_ret;

	i_ret = inter_ray_base_cy (cy, ray, val);
	if (i_ret.object == CYLINDER)
		return (i_ret);
	i_ret = inter_ray_top_cy (cy, ray, val);
	return (i_ret);
}

t_intersec	inter_ray_cy(t_cylinder cy, t_ray ray)
{
	t_cy_inter_values	val;
	t_intersec			i_ret;

	val = calc_inter_values(cy, ray);
	i_ret.object = NO_INTER;
	if (val.discriminant < 0 || val.t1 < 0)
		return (i_ret);
	val.sqrtDiscriminant = sqrt(val.discriminant);
	i_ret.t1 = val.t1;
	if (val.p1DotV >= 0 && val.p1DotV <= cy.cy_height)
	{
		i_ret.object = CYLINDER;
		i_ret.hit1 = val.hit1;
		i_ret.color = cy.cy_color;
		i_ret.n1 = calculate_normal_cy(cy, i_ret.hit1);
		return (i_ret);
	}
	i_ret = inter_ray_t_b_cy(cy, ray, val);
	return (i_ret);
}
