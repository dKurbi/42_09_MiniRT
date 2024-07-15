/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:56:39 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/04 18:31:44 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_if_s(char *sarg, int num)
{
	int	len;

	if (!sarg)
		return (num + write(1, "(null)", 6));
	len = ft_strlen(sarg);
	if (num < 0)
		return (num);
	if (ft_printf_w_typestr(sarg, num) == -1)
		return (-1);
	return (num + len);
}
