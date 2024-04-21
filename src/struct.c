/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:05:00 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/21 20:18:12 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	rtnew(t_rt *rt, int ac, char **av)
{
	rt->ac = ac;
	rt->av = av;
	rt->fd = -1;
	rt->save = NULL;
}
