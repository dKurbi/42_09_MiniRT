/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 04:04:42 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/06 04:11:39 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_sphere(t_sphere **sphere)
{
	t_sphere	*copy_sphere;

	if (*sphere == NULL)
		return ;
	(void)*sphere;
	(void)copy_sphere;
}

void	free_plane(t_plane **plane)
{
	t_plane	*copy_plane;

	if (*plane == NULL)
		return ;
	(void)*plane;
	(void)copy_plane;
}

void	free_cylinder(t_cylinder **cylinder)
{
	t_cylinder	*copy_cylinder;

	if (*cylinder == NULL)
		return ;
	(void)copy_cylinder;
	(void)*cylinder;
}
