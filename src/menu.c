/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:17:31 by iassambe          #+#    #+#             */
/*   Updated: 2024/08/19 17:42:46 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	print_menu(void)
{
	ft_printf("——————————————————————————————————————————————————————————\n");
	ft_printf("|	█▀█▀█    ▀█▀    █▄░█    ▀█▀    █▀█    █▀█▀█	 |\n");
	ft_printf("|	█░█░█    ▄█▄    █░▀█    ▄█▄    █▀▄    ░░█░░	 |\n");
	ft_printf("——————————————————————————————————————————————————————————\n");
	ft_printf("|		Welcome to miniRT project! 		 |\n");
	ft_printf("——————————————————————————————————————————————————————————\n");
	ft_printf("|	Press [ESC] key to exit				 |\n");
	ft_printf("|	Press [W] key to move forward		    	 |\n");
	ft_printf("|	Press [S] key to move backward			 |\n");
	ft_printf("|	Press [A] key to move left		    	 |\n");
	ft_printf("|	Press [D] key to move right			 |\n");
	ft_printf("|	Press [▲] key to turn up			 |\n");
	ft_printf("|	Press [▼] key to turn down			 |\n");
	ft_printf("|	Press [◄] key to turn left			 |\n");
	ft_printf("|	Press [►] key to turn right			 |\n");
	ft_printf("|	Press [+] key to zoom in			 |\n");
	ft_printf("|	Press [-] key to zoom out			 |\n");
	ft_printf("|	Press [B] key to make ambient light lighter	 |\n");
	ft_printf("|	Press [N] key to make ambient light darker	 |\n");
	ft_printf("|	Press [R] key to spin camera			 |\n");
	ft_printf("|	Press [T] key to spin camera inversely		 |\n");
	ft_printf("|	Press [M] key to show menu again		 |\n");
	ft_printf("——————————————————————————————————————————————————————————\n");
}
