/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/08/19 04:34:26 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing_loop(t_rt *rt, int x, int y)
{
	t_ray		ray;
	t_intersec	inter;

	if (check_is_inside(*rt, rt->scene.l_pos))
		rt->scene.l_bright = 0;
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
		}
	}
	mlx_put_image_to_window(rt->rtmlx.mlx_ptr, rt->rtmlx.win, \
							rt->rtmlx.img, 0, 0);
}

void	raytracing(t_rt *rt)
{
	int	x;
	int	y;

	if (check_is_inside(*rt, rt->scene.c_pos))
		print_black(rt);
	else
	{
		x = -1;
		y = -1;
		raytracing_loop(rt, x, y);
	}
	print_menu();
	printf("AFTERRAYTRACIN\n");
}

//MAIN: MAIN
int	main(int ac, char **av)
{
	t_rt	rt;

	rtnew(&rt, ac, av);
	if (ac != 2 || !av)
		exit(print_error(rt, ERR_INC_ARGS, NO_FREE_MLX));
	if (check_file(rt) > 0 || check_save_value(&rt) > 0)
		exit(ERROR);
	calc_up_right_vector(&rt);
	mlxnew(&rt);
	raytracing(&rt);
	mlx_hook(rt.rtmlx.win, EV_DESTROY, MASK_DESTROY, event_destroy, &rt);
	mlx_hook(rt.rtmlx.win, EV_KEY, 0, event_key, &rt);
	mlx_mouse_hook(rt.rtmlx.win, event_mouse, &rt);
	mlx_loop(rt.rtmlx.mlx_ptr);
	free_rt(&rt, FREE_MLX);
	return (0);
}
