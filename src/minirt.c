/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/06/12 16:56:25 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing(t_rt *rt)
{
	int			x;
	int			y;
	t_ray		ray;
	t_intersec	inter;
	double		t;


	x = -1;
	y = -1;
	t = tan(rt->scene.c_fov);
	while (++y < WIN_Y)
	{
		while (++x < WIN_X)
		{
			ray = make_ray(calc_ang_rot(x, y, t, rt->aspect_ratio), *rt);
			inter = found_inter(ray, *rt);
			if (inter.object != NO_INTER)
				pixel_put(*rt, x, y, get_color_inter(inter, *rt));
			else
				pixel_put(*rt, x, y, 0);
		}
		x = -1;
		//printf("\n");
	}
	print_scene(rt->scene);
	printf("fov = %f, tan = %f\n", rt->scene.c_fov, t);
	mlx_put_image_to_window(rt->rtmlx.mlx_ptr, rt->rtmlx.win, \
							rt->rtmlx.img, 0, 0);
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
