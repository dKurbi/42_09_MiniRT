/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:48:25 by diego             #+#    #+#             */
/*   Updated: 2024/06/02 19:01:54 by iassambe         ###   ########.fr       */
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
t_vector2	calc_ang_rot(int x, int y, double fov, double aspect_ratio)
{
	t_vector2	ret;

	ret.x = (((double) x - WIN_X / 2) / WIN_X / 2) * fov;
	ret.y = (((double) y - WIN_Y / 2) / WIN_X / 2) * (fov / aspect_ratio);
	return (ret);
}

t_vector rotation_axis(t_vector v, t_vector u, double ang)
{
	t_vector new;
	double	cs;
	double	sn;
	
	cs = cos(ang);
	sn = sin(ang);
	new.x = v.x * (cs + (pow(u.x, 2) * (1 - cs))) + \
		v.y * (u.x * u.y * (1 - cs) - u.z * sn) + \
		v.z * (u.x * u.z * (1- cs) + u.y * sn);
	new.y = v.x * (u.y * u.x * (1 - cs) + u.z * sn) + \
		v.y * (cs + pow(u.y, 2) * (1 -cs)) + \
		v.z * (u.y * u.z * (1 - cs) - u.x * sn);
	new.z = v.x * (u.z * u.x * (1- cs) - u.y * sn) + \
		v.y * (u.z * u.y * (1 - cs) + u.x * sn) + \
		v.z * (cs + pow(u.z, 2) * (1 - cs));
	return (new);
}

void calc_up_right_vector(t_rt *rt)
{
	if (rt->scene.c_dir.x || rt->scene.c_dir.y)
	{
		rt->scene.v_up.x = rt->scene.c_dir.y;
		rt->scene.v_up.y = -rt->scene.c_dir.x;
		rt->scene.v_up.z = 0;
		rt->scene.v_up = v_normalized(rt->scene.v_up);
		rt->scene.v_right = v_normalized(v_cross(rt->scene.v_up, rt->scene.c_dir));
	}
	else if (rt->scene.c_dir.z)
	{
		rt->scene.v_up.z = rt->scene.c_dir.y;
		rt->scene.v_up.y = -rt->scene.c_dir.z;
		rt->scene.v_up.x = 0;
		rt->scene.v_up = v_normalized(rt->scene.v_up);
		rt->scene.v_right = v_normalized(v_cross(rt->scene.v_up, rt->scene.c_dir));
	} else
	{
		rt->scene.v_up.x = 1;
		rt->scene.v_up.y = 0;
		rt->scene.v_up.z = 0;
		rt->scene.v_right.x = 0;
		rt->scene.v_right.y = 1;
		rt->scene.v_right.z = 0;
	}
}
