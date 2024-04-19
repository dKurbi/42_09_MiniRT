/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_w_typechar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:59:40 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/04 18:32:48 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_w_typechar(int const s, int num)
{
	if (write(1, &s, 1) < 0)
		return (-1);
	else
		return (num + 1);
}
