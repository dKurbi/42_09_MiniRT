/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:38:26 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/15 14:34:52 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cy_inter_values calc_inter_values(t_cylinder cy, t_ray ray)
{
	t_cy_inter_values val;

    val.halfHeightVec = v_expand(cy.cy_axis, cy.cy_height / 2.0);
    val.cylBase = v_rest(cy.cy_center, val.halfHeightVec);
    val.cylTop = v_add(cy.cy_center, val.halfHeightVec);
    cy.cy_axis = v_normalized(cy.cy_axis);
    val.deltaP = v_rest(ray.start, val.cylBase);
    val.dDotV = v_dot(ray.direction, cy.cy_axis);
    val.deltaPDotV = v_dot(val.deltaP, cy.cy_axis);
    val.v_a = v_rest(ray.direction, v_expand(cy.cy_axis, val.dDotV));
    val.v_b = v_rest(val.deltaP, v_expand(cy.cy_axis, val.deltaPDotV));
    val.a = v_dot(val.v_a, val.v_a);
    val.b = 2 * v_dot(val.v_a, val.v_b);
    val.c = v_dot(val.v_b, val.v_b) - pow(cy.cy_diam/2, 2);
	val.discriminant = pow(val.b, 2) - 4 * val.a * val.c;
    if (val.discriminant < 0) 
        return (val); 
    val.sqrtDiscriminant = sqrt(val.discriminant);
 	val.t1 = (-val.b - val.sqrtDiscriminant) / (2 * val.a);
    val.t2 = (-val.b + val.sqrtDiscriminant) / (2 * val.a); 
	if (val.t2 < val.t1)
		val.t1 = val.t2;
	val.hit1 = v_add(ray.start, v_expand(ray.direction, val.t1));
	val.p1DotV = v_dot(v_rest(val.hit1, val.cylBase), cy.cy_axis);
	return (val);
}

t_vector calculate_normal(t_cylinder cy, t_vector hit) 
{
    t_vector cy_to_hit = v_rest(hit, cy.cy_center);
    double proj_length = v_dot(cy_to_hit, cy.cy_axis);
    t_vector proj_point = v_add(cy.cy_center, v_expand(cy.cy_axis, proj_length));
    return v_normalized(v_rest(hit, proj_point));
}

t_intersec inter_ray_cy(t_cylinder cy, t_ray ray) 
{
	t_cy_inter_values val;
	t_intersec i_ret;
	
	val = calc_inter_values(cy, ray);
	i_ret.object = NO_INTER;
    if (val.discriminant < 0 || val.t1 < 0) 
        return (i_ret); 
    val.sqrtDiscriminant = sqrt(val.discriminant);
	i_ret.t1 = val.t1;
	if (val.p1DotV >=0 && val.p1DotV <= cy.cy_height)
	{
		i_ret.object = CYLINDER;
		i_ret.hit1 = val.hit1;
		i_ret.color = cy.cy_color;
        i_ret.n1 = v_expand(calculate_normal(cy, i_ret.hit1), -1);
	}
    return (i_ret);
}


