/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 04:04:42 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/07 04:53:34 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_sphere(t_sphere **sphere)
{
	t_sphere	*copy_sphere;

	if (*sphere == NULL)
		return ;
	while (*sphere)
	{
		copy_sphere = (*sphere);
		*sphere = (*sphere)->next;
		free(copy_sphere);
	}
	*sphere = NULL;
}

void	free_plane(t_plane **plane)
{
	t_plane	*copy_plane;

	if (*plane == NULL)
		return ;
	while (*plane)
	{
		copy_plane = (*plane);
		*plane = (*plane)->next;
		free(copy_plane);
	}
}

void	free_cylinder(t_cylinder **cylinder)
{
	t_cylinder	*copy_cylinder;

	if (*cylinder == NULL)
		return ;
	while (*cylinder)
	{
		copy_cylinder = (*cylinder);
		*cylinder = (*cylinder)->next;
		free(copy_cylinder);
	}
}
