/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cy_calc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:45:45 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/08/17 21:00:54 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	calc_cy_values(t_cylinder *cy)
{
	cy->cy_axis = v_normalized(cy->cy_axis);
	cy->cy_half_vec = v_expand(cy->cy_axis, cy->cy_height / 2.0);
	cy->cy_base = v_rest(cy->cy_center, cy->cy_half_vec);
	cy->cy_top = v_add(cy->cy_center, cy->cy_half_vec);
}

t_cy_inter_values	calc_inter_values(t_cylinder cy, t_ray ray)
{
	t_cy_inter_values	val;

	val.delta_p = v_rest(ray.start, cy.cy_base);
	val.d_dot_v = v_dot(ray.direction, cy.cy_axis);
	val.delta_p_dot_v = v_dot(val.delta_p, cy.cy_axis);
	val.v_a = v_rest(ray.direction, v_expand(cy.cy_axis, val.d_dot_v));
	val.v_b = v_rest(val.delta_p, v_expand(cy.cy_axis, val.delta_p_dot_v));
	val.a = v_dot(val.v_a, val.v_a);
	val.b = 2 * v_dot(val.v_a, val.v_b);
	val.c = v_dot(val.v_b, val.v_b) - pow(cy.cy_diam / 2, 2);
	val.discrim = pow(val.b, 2) - 4 * val.a * val.c;
	if (val.discrim < 0)
		return (val);
	val.sqrt_discrim = sqrt(val.discrim);
	val.t1 = (-val.b - val.sqrt_discrim) / (2 * val.a);
	val.t2 = (-val.b + val.sqrt_discrim) / (2 * val.a);
	val.t1 = choose_t (val.t1, val.t2);
	val.hit1 = v_add(ray.start, v_expand(ray.direction, val.t1));
	val.p1DotV = v_dot(v_rest(val.hit1, cy.cy_base), cy.cy_axis);
	return (val);
}

t_vector	calculate_normal_cy(t_cylinder cy, t_vector hit)
{
	t_vector	cy_to_hit;
	t_vector	proj_point;
	double		proj_length;

	cy_to_hit = v_rest(hit, cy.cy_center);
	proj_length = v_dot(cy_to_hit, cy.cy_axis);
	proj_point = v_add(cy.cy_center, v_expand(cy.cy_axis, proj_length));
	return (v_normalized(v_rest(hit, proj_point)));
}
