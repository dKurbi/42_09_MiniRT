/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:48:25 by diego             #+#    #+#             */
/*   Updated: 2024/05/27 04:28:37 by iassambe         ###   ########.fr       */
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

t_vector2	calc_ang_rot(int x, int y, double fov, double aspect_ratio)
{
	t_vector2	ret;

	ret.x = (((double) x - WIN_X / 2) / WIN_X / 2) * fov;
	ret.y = (((double) y - WIN_Y / 2) / WIN_X / 2) * (fov / aspect_ratio);
	return (ret);
}
