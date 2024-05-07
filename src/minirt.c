/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/07 04:59:44 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//MAIN: TESTER MAIN FOR FUNCTIONS test test test
// test check_str_number
/* int main(int ac, char **av)
{
	double		fl;
	int			i;
	t_rgb		color;
	t_vector	vector;

	(void)color;
	(void)i;
	(void)fl;
	(void)vector;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	i = 0;
	if (ac == 1)
		return (0);
 	if (!check_is_a_float(av[1], &i, &fl))
		printf("el numero es el float = %f\n", fl);
	else	
		printf("el argumento no es float\n");
	printf("atof orig - %f\n", atof(av[1]));
	
	printf("part check_rgb -----------------\n\n\n\n");

 	if (check_is_a_rgb(av[1], &i, &color))
		return (1);
	printf("r - %d, g - %d, b - %d\n", color.r, color.g, color.b);
	if (check_is_a_vector(av[1], &i, &vector))
		return (1);
	printf("x - %f, y - %f, z - %f\n", vector.x, vector.y, vector.z);
	t_vector vector2;
	vector2.x = 0;
	vector2.y = 0;
	i = 0;
	vector2.z = 0;
	if (check_is_a_vector_range(av[1], &i, &vector2))
		return (1);
	printf("range x - %f, y - %f, z - %f\n", vector2.x, vector2.y, vector2.z);
	printf("i after all - %d\n", i);
	return 0;
} */

//MAIN: MAIN
int	main(int ac, char **av)
{
	t_rt	rt;

	//printf("BITWISE MASKS: 1L - %ld\n", 1L << 0);//debug for linux mask mlx
	rtnew(&rt, ac, av);
	if (ac != 2 || !av)
		exit(print_error(rt, ERR_INC_ARGS, NO_FREE_MLX));
	if (check_file(rt) > 0 || check_save_value(&rt) > 0)
	{
		if (rt.scene.sp == NULL)
			printf("sphere nul\n");
		exit(ERROR);
	}	
	///printf part
	//printf("A - ratio - %f; rgb - %d, %d, %d\n", rt.scene.a_l_ratio, rt.scene.a_l_color.r, rt.scene.a_l_color.g, rt.scene.a_l_color.b);
	//printf("C - vector - %f, %f, %f; vector - %f, %f, %f; dir - %f\n", rt.scene.c_pos.x, rt.scene.c_pos.y, rt.scene.c_pos.z, rt.scene.c_dir.x, rt.scene.c_dir.y, rt.scene.c_dir.z, rt.scene.c_fov);
	//printf("L - vector - %f, %f, %f; float - %f\n", rt.scene.l_pos.x, rt.scene.l_pos.y, rt.scene.l_pos.z, rt.scene.l_bright);
	//printf("sp - vector - %f, %f, %f; float - %f; rgb - %d, %d, %d\n", rt.scene.sp->sp_center.x, rt.scene.sp->sp_center.y, rt.scene.sp->sp_center.z, rt.scene.sp->sp_diam, rt.scene.sp->sp_color.r, rt.scene.sp->sp_color.g, rt.scene.sp->sp_color.b);
	//printf("pl - vector - %f, %f, %f; vector - %f, %f, %f; rgb - %d, %d, %d\n", rt.scene.pl->pl_point.x, rt.scene.pl->pl_point.y, rt.scene.pl->pl_point.z, rt.scene.pl->pl_normal.x, rt.scene.pl->pl_normal.y, rt.scene.pl->pl_normal.z, rt.scene.pl->pl_color.r, rt.scene.pl->pl_color.g, rt.scene.pl->pl_color.b);
	//printf("cy - vector - %f, %f, %f; vector - %f, %f, %f; float - %f; float - %f; rgb - %d, %d, %d\n", rt.scene.cy->cy_center.x, rt.scene.cy->cy_center.y, rt.scene.cy->cy_center.z, rt.scene.cy->cy_axis.x, rt.scene.cy->cy_axis.y, rt.scene.cy->cy_axis.z, rt.scene.cy->cy_diam, rt.scene.cy->cy_height, rt.scene.cy->cy_color.r, rt.scene.cy->cy_color.g, rt.scene.cy->cy_color.b);
	
	mlxnew(&rt);
	mlx_hook(rt.rtmlx.win, EV_KEY, 0, event_key, &rt);
	mlx_mouse_hook(rt.rtmlx.win, event_mouse, &rt);
	mlx_hook(rt.rtmlx.win, EV_DESTROY, MASK_DESTROY, event_destroy, &rt);
	mlx_loop(rt.rtmlx.init);
	free_rt(&rt, FREE_MLX);
	return (0);
}

