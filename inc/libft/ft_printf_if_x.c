/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:00:41 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/07 21:19:41 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_len_for_malloc(unsigned int uarg)
{
	int	malloclen;

	malloclen = 0;
	while (uarg != 0)
	{
		malloclen++;
		uarg = uarg / 16;
	}
	return (malloclen);
}

int	ft_x_conv_w(unsigned int uarg, char *base, char *arr, int len)
{
	int	i;

	i = 0;
	while (uarg != 0)
	{
		arr[i] = base[uarg % 16];
		uarg = uarg / 16;
		i++;
	}
	arr[i] = '\0';
	len = ft_strlen(arr);
	while (--i >= 0)
	{
		if (ft_printf_w_typechar(arr[i], 0) < 0)
			return (-1);
	}
	return (len);
}

int	ft_printf_if_x(unsigned int uarg, int num, char *base)
{
	int				len;
	char			*arr;
	int				malloclen;

	if (num < 0)
		return (num);
	if (uarg == 0)
		return (num + write(1, "0", 1));
	malloclen = ft_x_len_for_malloc(uarg);
	arr = (char *) malloc(sizeof(char) * (malloclen + 1));
	if (arr == NULL)
	{
		free(arr);
		return (-1);
	}
	len = 0;
	len = ft_x_conv_w(uarg, base, arr, len);
	if (len < 0)
	{
		free(arr);
		return (-1);
	}
	free(arr);
	return (num + len);
}
