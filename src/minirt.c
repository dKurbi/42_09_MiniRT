/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/29 15:26:55 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// test check_str_number
int main(int ac, char **av)
{
	float	fl;
	int		i;

	i = 0;
	if (ac == 1)
		return(0);
	if (!check_is_a_float(av[1], &i, &fl))
		printf("el numero es el float = %f\n", fl);
	else	
		printf("el argumento no es float\n");
}
/*
int	main(int ac, char **av)
{
	t_rt	rt;

	printf("BITWISE MASKS: 1L - %ld\n", 1L << 0);
	rtnew(&rt, ac, av);
	if (ac != 2 || !av)
		exit(print_error(rt, ERR_INC_ARGS, NO_FREE_MLX));
	if (check_file(rt) > 0)
		exit(ERROR);
	if (init_scene(rt) > 0)
		exit(print_error(rt, ERR_INIT_SCENE, NO_FREE_MLX));
	mlxnew(&rt);
	mlx_hook(rt.rtmlx.win, EV_KEY, 0, event_key, &rt);
	mlx_mouse_hook(rt.rtmlx.win, event_mouse, &rt);
	mlx_hook(rt.rtmlx.win, EV_DESTROY, MASK_DESTROY, event_destroy, &rt);
	mlx_loop(rt.rtmlx.init);
	free_rt(&rt, FREE_MLX);
	return (0);
}
*/
