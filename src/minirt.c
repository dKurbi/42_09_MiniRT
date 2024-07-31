/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/31 12:50:32 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing(t_rt *rt)
{
	int			x;
	int			y;
	t_ray		ray;
	t_intersec	inter;

	if (check_cam_is_inside(*rt))
		print_black(rt);
	else
	{
		y = -1;
		while (++y < WIN_Y)
		{
		x = -1;
			while (++x < WIN_X)
			{
				ray = make_ray(calc_ang_rot(x, y, *rt), *rt);
				inter = found_inter(ray, *rt, NO_INTER, -1);
				if (inter.object != NO_INTER)
					pixel_put(*rt, x, y, get_color_inter(inter, *rt));
				else
					pixel_put(*rt, x, y, 0);
		//	if (y %40 == 0 && x % 40 == 0)
		//			printf("%d.%d|", inter.object, inter.index);
			}
		//	if (y %40 == 0)
		//		printf("\n");
		}
		//print_scene(rt->scene);
		mlx_put_image_to_window(rt->rtmlx.mlx_ptr, rt->rtmlx.win, \
								rt->rtmlx.img, 0, 0);
	}
}

//MAIN: MAIN
int	main(int ac, char **av)
{
	t_rt	rt;

	printf("BITWISE MASKS: 1L << 0 - %ld\n", 1L << 0);
	rtnew(&rt, ac, av);
	if (ac != 2 || !av)
		exit(print_error(rt, ERR_INC_ARGS, NO_FREE_MLX));
	if (check_file(rt) > 0 || check_save_value(&rt) > 0)
		exit(ERROR);
	calc_up_right_vector(&rt);
	mlxnew(&rt);
	raytracing(&rt);
	mlx_hook(rt.rtmlx.win, EV_KEY, 0, event_key, &rt);
	mlx_mouse_hook(rt.rtmlx.win, event_mouse, &rt);
	mlx_hook(rt.rtmlx.win, EV_DESTROY, MASK_DESTROY, event_destroy, &rt);
	mlx_loop(rt.rtmlx.mlx_ptr);
	free_rt(&rt, FREE_MLX);
	return (0);
}
