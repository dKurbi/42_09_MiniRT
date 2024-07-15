/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:58:14 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/04 18:32:08 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printf_if_u_len(unsigned int uarg)
{
	unsigned int	len;
	unsigned int	uargcopy;

	len = 0;
	uargcopy = uarg;
	if (uargcopy == 0)
		return (1);
	while (0 < uargcopy)
	{
		len++;
		uargcopy = uargcopy / 10;
	}
	return (len);
}

char	*ft_printf_if_u_arr(unsigned int uarg, char *arr, unsigned int len)
{
	if (uarg >= 10)
		arr = ft_printf_if_u_arr(uarg / 10, arr, len - 1);
	arr[len] = uarg % 10 + '0';
	arr[len + 1] = '\0';
	return (arr);
}

char	*ft_printf_if_u_uitoa(unsigned int uarg)
{
	char			*arr;
	unsigned int	len;

	arr = NULL;
	len = ft_printf_if_u_len(uarg);
	arr = (char *) malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	if (uarg == 0)
	{
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	arr = ft_printf_if_u_arr(uarg, arr, len - 1);
	return (arr);
}

int	ft_printf_if_u(unsigned int uarg, int num)
{
	char	*arr;
	int		len;

	if (num < 0)
		return (num);
	arr = ft_printf_if_u_uitoa(uarg);
	if (arr == NULL)
	{
		free(arr);
		return (-1);
	}
	len = (int)ft_strlen(arr);
	if (ft_printf_w_typestr(arr, num) == -1)
	{
		free(arr);
		return (-1);
	}
	free(arr);
	return (num + len);
}
