/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:50:10 by iassambe          #+#    #+#             */
/*   Updated: 2024/06/05 18:02:37 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"



void	raytracing(t_rt *rt)
{
	int			x;
	int			y;
	t_ray		ray;
	t_intersec	inter;
	int			c;

	x = -1;
	y = -1;
	while (++y < WIN_Y)
	{
		while (++x < WIN_X)
		{			
			ray = make_ray(calc_ang_rot(x, y, rt->scene.c_fov, rt->aspect_ratio), *rt);
			inter = found_inter(ray, *rt);
			if (inter.object != NO_INTER)
				c = get_color_inter(inter, *rt);
			else
				c = 0;
			pixel_put(*rt, x, y, c);
		}
		x = -1;
		//printf("\n");
	}
	print_scene(rt->scene);
	mlx_put_image_to_window(rt->rtmlx.mlx_ptr, rt->rtmlx.win, \
							rt->rtmlx.img, 0, 0);
}

/* void	raytracing(t_rt *rt)
{
	int			x;
	int			y;
	t_vector2	v_rot;
	t_ray		ray;
	t_intersec	inter;
	int			c;
	t_vector	l_dir;
	double		nxl;

	x = -1;
	y = -1;
	while (++y < WIN_Y)
	{
		while (++x < WIN_X)
		{
			v_rot = calc_ang_rot(x, y, rt->scene.c_fov, rt->aspect_ratio);
			ray = make_ray(v_rot, *rt);
			inter = inter_ray_sp(rt->scene.sp[0], ray);
			if (inter.object != NO_INTER)
			{
				l_dir =v_normalized(v_rest(inter.h1, rt->scene.l_pos));
				nxl = pow (v_dot(l_dir, inter.n1), 100);
				if (nxl < 0)
					nxl = 0;
				//print_rgb("color", inter.color);
				int r =inter.color.r * nxl; 
				int g = inter.color.g * nxl;
				int b = inter.color.b * nxl;
				c = color(r, g ,b );
				pixel_put(*rt, x, y, c);
				//printf("x = %d, y = %d, t1 =  %f, t2 = %f, nxl = %f \n", x, y, inter.t1, inter.t2, nxl);
				//printf("c= %, r = %d, g = %d, b = %d\n", c, r, g, b);
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
 */
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
