/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:17:31 by iassambe          #+#    #+#             */
/*   Updated: 2024/08/19 04:14:54 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	print_menu_mouse(void)
{
	ft_printf("——————————————————————————————————————————————————————————\n");
	ft_printf("|	Click RIGHT to make ambient light lighter	 |\n");
	ft_printf("|	Click LEFT to make ambient light darker		 |\n");
	ft_printf("|	Spin wheel UP to zoom in			 |\n");
	ft_printf("|	Spin wheel DOWN to zoom out			 |\n");
	ft_printf("——————————————————————————————————————————————————————————\n");
}

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
	ft_printf("|	Press [▲] key to turn up			 |\n");
	ft_printf("|	Press [▼] key to turn down			 |\n");
	ft_printf("|	Press [◄] key to turn left			 |\n");
	ft_printf("|	Press [►] key to turn right			 |\n");
	ft_printf("|	Press [+] key to zoom in			 |\n");
	ft_printf("|	Press [-] key to zoom out			 |\n");
	ft_printf("|	Press [B] key to make ambient light lighter	 |\n");
	ft_printf("|	Press [N] key to make ambient light darker	 |\n");
	ft_printf("|	Press [R] key to spin object			 |\n");
	ft_printf("|	Press [T] key to spin inversely 		 |\n");
	ft_printf("|	Press [M] key to show menu again		 |\n");
	print_menu_mouse();
}
