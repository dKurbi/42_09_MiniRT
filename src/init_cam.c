/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:04:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/05/20 20:02:52 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_cam(t_rt *rt)
{
	rt->scene.c_foward = v_normalized(v_rest(rt->scene.c_dir, rt->scene.c_dir));
}
