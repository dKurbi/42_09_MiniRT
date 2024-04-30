/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/30 02:09:29 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//MAIN: TESTER MAIN FOR FUNCTIONS test test test
// test check_str_number
int main(int ac, char **av)
{
	double	fl;
	int		i;
	t_rgb	color;

	(void)color;
	(void)i;
	(void)fl;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	i = 0;
	if (ac == 1)
		return (0);
/* 	if (!check_is_a_float(av[1], &i, &fl))
		printf("el numero es el float = %f\n", fl);
	else	
		printf("el argumento no es float\n");
	printf("atof orig - %f\n", atof(av[1])); */
	
	printf("part check_rgb -----------------\n\n\n\n");

	if (check_is_a_rgb(av[1], &i, &color))
		return (1);
	printf("r - %d, g - %d, b - %d\n", color.r, color.g, color.b);
	return 0;
}

//MAIN: MAIN
/* int	main(int ac, char **av)
{
	t_rt	rt;

	printf("BITWISE MASKS: 1L - %ld\n", 1L << 0);
	rtnew(&rt, ac, av);
	if (ac != 2 || !av)
		exit(print_error(rt, ERR_INC_ARGS, NO_FREE_MLX));
	if (check_file(rt) > 0)
		exit(ERROR);
	mlxnew(&rt);
	mlx_hook(rt.rtmlx.win, EV_KEY, 0, event_key, &rt);
	mlx_mouse_hook(rt.rtmlx.win, event_mouse, &rt);
	mlx_hook(rt.rtmlx.win, EV_DESTROY, MASK_DESTROY, event_destroy, &rt);
	mlx_loop(rt.rtmlx.init);
	free_rt(&rt, FREE_MLX);
	return (0);
} */

