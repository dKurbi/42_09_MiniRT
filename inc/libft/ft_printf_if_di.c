/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:57:54 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/04 18:31:30 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_if_di(int numarg, int num)
{
	char	*arr;
	int		len;

	if (num < 0)
		return (num);
	if (numarg == '\0')
		return (ft_printf_w_typechar('0', num));
	arr = ft_itoa(numarg);
	if (arr == NULL)
	{
		free(arr);
		return (-1);
	}
	len = ft_strlen(arr);
	if (ft_printf_w_typestr(arr, num) == -1)
	{
		free(arr);
		return (-1);
	}
	free(arr);
	return (num + len);
}
