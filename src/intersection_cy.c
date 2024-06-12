/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:38:26 by iassambe          #+#    #+#             */
/*   Updated: 2024/06/12 14:07:16 by dkurcbar         ###   ########.fr       */
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
	val.hit1 = v_add(ray.start, v_expand(ray.direction, val.t1));
    val.hit2 = v_add(ray.start, v_expand(ray.direction, val.t2));
	val.p1DotV = v_dot(v_rest(val.hit1, val.cylBase), cy.cy_axis);
    val.p2DotV = v_dot(v_rest(val.hit2, val.cylBase), cy.cy_axis);
	return (val);
}

t_intersec inter_ray_cy(t_cylinder cy, t_ray ray) 
{
	t_cy_inter_values val;
	t_intersec i_ret;
	
	val = calc_inter_values(cy, ray);
	i_ret.object = NO_INTER;
    if (val.discriminant < 0) 
        return (i_ret); 
    val.sqrtDiscriminant = sqrt(val.discriminant);
    i_ret.t1 = val.t1;
    i_ret.t2 = val.t2;
    if (val.p1DotV >=0 && val.p1DotV <= cy.cy_height)
	{
		i_ret.object = CYLINDER;
		i_ret.hit1 = val.hit1;
		i_ret.color = cy.cy_color;
	}
	if (val.p2DotV >= 0 && val.p2DotV <= cy.cy_height)
	{
		i_ret.object = CYLINDER;
		i_ret.hit2 = val.hit2;
		i_ret.color = cy.cy_color;
	}
    return (i_ret);
}

void a()
{
	
}

