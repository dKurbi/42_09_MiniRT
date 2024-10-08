/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:48:25 by diego             #+#    #+#             */
/*   Updated: 2024/08/17 21:05:44 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vector	rotation_x(t_vector v, double ang)
{
	t_vector	new;

	new.x = v.x;
	new.y = v.y * cos(ang) - v.z * sin(ang);
	new.z = v.y * sin(ang) + v.z * cos(ang);
	return (new);
}

t_vector	rotation_y(t_vector v, double ang)
{
	t_vector	new;

	new.x = cos(ang) * v.x + sin (ang) * v.z;
	new.y = v.y;
	new.z = -sin(ang) * v.x + cos(ang) * v.z;
	return (new);
}

//calculate the rotation angle for each x,y pixel
t_vector2	calc_ang_rot(int x, int y, t_rt rt)
{
	t_vector2	ret;
	double		norm_x;
	double		norm_y;

	norm_x = ((double)(2 * x - WIN_X)) / WIN_X ;
	ret.x = norm_x * rt.scene.c_fov_tan;
	norm_y = ((double)(2 * y - WIN_Y)) / WIN_X ;
	ret.y = norm_y * (rt.scene.c_fov_tan / rt.aspect_ratio);
	return (ret);
}

t_vector	rotation_axis(t_vector v, t_vector u, double ang)
{
	t_vector	new;
	double		cs;
	double		sn;

	cs = cos(ang);
	sn = sin(ang);
	new.x = v.x * (cs + (pow(u.x, 2) * (1 - cs))) + \
		v.y * (u.x * u.y * (1 - cs) - u.z * sn) + \
		v.z * (u.x * u.z * (1 - cs) + u.y * sn);
	new.y = v.x * (u.y * u.x * (1 - cs) + u.z * sn) + \
		v.y * (cs + pow(u.y, 2) * (1 - cs)) + \
		v.z * (u.y * u.z * (1 - cs) - u.x * sn);
	new.z = v.x * (u.z * u.x * (1 - cs) - u.y * sn) + \
		v.y * (u.z * u.y * (1 - cs) + u.x * sn) + \
		v.z * (cs + pow(u.z, 2) * (1 - cs));
	return (new);
}

void	calc_up_right_vector(t_rt *rt)
{
	rt->scene.c_dir = v_normalized(rt->scene.c_dir);
	if (fabs(v_dot(rt->scene.c_dir, v_new(1, 0, 0))) != 1)
	{
		rt->scene.v_up = v_cross(rt->scene.c_dir, v_new(-1, 0, 0));
		rt->scene.v_up = v_normalized(rt->scene.v_up);
		rt->scene.v_right = v_normalized(v_cross(rt->scene.v_up, \
			rt->scene.c_dir));
	}
	else
	{
		rt->scene.v_up = v_cross(rt->scene.c_dir, v_new(0, 0, 1));
		rt->scene.v_right = v_normalized(v_cross(rt->scene.v_up, \
		rt->scene.c_dir));
	}
}
