/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:29:49 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/08 20:01:40 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_cspdiux(const char *s, va_list argsva, int num)
{
	if (*s == '%')
		num = ft_printf_w_typechar('%', num);
	else if (*s == 'c')
		num = ft_printf_if_c(va_arg(argsva, int), num);
	else if (*s == 's')
		num = ft_printf_if_s(va_arg(argsva, char *), num);
	else if (*s == 'p')
		num = ft_printf_if_p(va_arg(argsva, void *), num);
	else if (*s == 'd' || *s == 'i')
		num = ft_printf_if_di(va_arg(argsva, int), num);
	else if (*s == 'u')
		num = ft_printf_if_u(va_arg(argsva, unsigned int), num);
	else if (*s == 'x')
		num = ft_printf_if_x(va_arg(argsva, unsigned int), \
		num, "0123456789abcdef");
	else if (*s == 'X')
		num = ft_printf_if_x(va_arg(argsva, unsigned int), \
		num, "0123456789ABCDEF");
	else
		num = num + ft_printf_w_typechar(*s, num);
	return (num);
}

int	ft_printf_loop(char const *s, va_list argsva, int num)
{
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			num = ft_printf_cspdiux(s, argsva, num);
			if (num < 0)
				return (num);
		}
		else
		{
			num = ft_printf_w_typechar(*s, num);
			if (num < 0)
				return (num);
		}
		s++;
	}
	return (num);
}

int	ft_printf(char const *s, ...)
{
	int		num;
	va_list	argsva;

	num = 0;
	if (!(s))
		return (0);
	va_start(argsva, s);
	num = ft_printf_loop(s, argsva, num);
	va_end(argsva);
	return (num);
}
