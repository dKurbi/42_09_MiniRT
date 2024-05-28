/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/28 19:39:54 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing(t_rt *rt)
{
	int			x;
	int			y;
	t_vector2	v_rot;
	t_ray		ray;
	t_intersec	inter;

	x = -1;
	y = -1;
	while (++y < WIN_Y)
	{
		while (++x < WIN_X)
		{
			v_rot = calc_ang_rot(x, y, rt->scene.c_fov, rt->aspect_ratio);
			ray = make_ray(v_rot, rt->scene.c_pos, rt->scene.c_dir);
			inter = inter_ray_sp(rt->scene.sp[0], ray);
			if (inter.object != NO_INTER)
			{
				pixel_put(*rt, x, y, \
						color(inter.color.r, inter.color.g, inter.color.b));
				//printf("t1= %f\n",inter.t1);
			}
			else
				pixel_put(*rt, x, y, 0x0);
		}
		x = -1;
		//printf("\n");
	}
	print_scene(rt->scene);
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
	mlxnew(&rt);
	raytracing(&rt);
	mlx_hook(rt.rtmlx.win, EV_KEY, 0, event_key, &rt);
	mlx_mouse_hook(rt.rtmlx.win, event_mouse, &rt);
	mlx_hook(rt.rtmlx.win, EV_DESTROY, MASK_DESTROY, event_destroy, &rt);
	mlx_loop(rt.rtmlx.mlx_ptr);
	free_rt(&rt, FREE_MLX);
	return (0);
}
