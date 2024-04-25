/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 04:54:49 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int ac, char **av)
{
	t_rt	rt;

	rtnew(&rt, ac, av);
	if (ac != 2 || !av)
		exit(print_error(rt, ERR_INC_ARGS, ERROR));
	if (check_file(rt) > 0)
		exit(ERROR);
	mlxnew(&rt);
	//mlx_key_hook();
	mlx_hook(rt.rtmlx.win, EV_KEY, 0, event_key, &rt);
	mlx_hook(rt.rtmlx.win, EV_DESTROY, 1L<<0, event_destroy, &rt);
	mlx_loop(rt.rtmlx.init);
	free_rt(&rt);
	return (0);
}
