/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:38:26 by iassambe          #+#    #+#             */
/*   Updated: 2024/06/11 19:18:37 by dkurcbar         ###   ########.fr       */
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
		i_ret.hit1 = v_add(v_expand(ray.direction, i_ret.t1), ray.start);
		i_ret.hit2 = v_add(v_expand(ray.direction, i_ret.t2), ray.start);
		i_ret.n1 = v_normalized(v_rest(i_ret.hit1, sp.sp_center));
		i_ret.n2 = v_normalized(v_rest(i_ret.hit2, sp.sp_center));
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
		i_ret.t1 = (v_dot(pl.pl_point, pl.pl_normal) - \
					v_dot(ray.start, pl.pl_normal)) / dn;
		i_ret.color = pl.pl_color;
		i_ret.ray = ray;
		i_ret.hit1 = v_add(v_expand(ray.direction, i_ret.t1), ray.start);
		i_ret.n1 = v_normalized(pl.pl_normal);
		i_ret.object = PLANE;
	}
	return (i_ret);
}

t_intersec inter_ray_cy(t_cylinder cy, t_ray ray) 
{
    
	t_intersec i_ret;
	t_vector A = v_rest(v_add(ray.start,v_expand(ray.direction,5)), cy.cy_center); // ray staty- cy_center
    t_vector d_cross_v = v_cross(ray.direction, cy.cy_axis); //producto cruz entre direccion de la recta y direccion del cilindro
    t_vector A_cross_v = v_cross(A, cy.cy_axis); // producto  cruz entre el vector entre el centro y el eje del cilindro

    double a = v_dot(d_cross_v, d_cross_v);
    double b = 2 * v_dot(A_cross_v, d_cross_v);
    double c = v_dot(A_cross_v, A_cross_v) - pow((double) cy.cy_diam/2, 2);
	printf("a = %f, b= %f, c = %f, v_dot(A_cros_v,A_cros_v) = %f\n", a, b, c, v_dot(A_cross_v, A_cross_v));
    double discriminant = pow(b,2) - 4 * a * c;
	i_ret.object = NO_INTER;
    if (discriminant < 0) 
        return (i_ret); // No intersection
    i_ret.t1 = (-b - sqrtf(discriminant)) / (2 * a);
    i_ret.t2 = (-b + sqrtf(discriminant)) / (2 * a);
	i_ret.object = CYLINDER;
	i_ret.hit1 = v_add(v_expand(ray.direction, i_ret.t1), ray.start);
	i_ret.hit2 = v_add(v_expand(ray.direction, i_ret.t2), ray.start);
	i_ret.color = cy.cy_color;
	print_rgb("cylinder color", cy.cy_color);
	print_v("hit cy = ", i_ret.hit1);
	
    return i_ret; // Intersection found
}
