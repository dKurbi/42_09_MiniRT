/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_w_typestr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:55:24 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/04 18:32:58 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_w_typestr(char const *s, int num)
{
	int		len;

	len = ft_strlen(s);
	if (len == 0 || num < 0)
		return (num);
	if (write(1, s, len) < 0)
		return (-1);
	return (num + len);
}
