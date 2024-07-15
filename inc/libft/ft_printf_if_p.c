/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_if_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:57:12 by iassambe          #+#    #+#             */
/*   Updated: 2023/06/08 18:05:26 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_if_p_len(void *nontypearg, int len)
{
	unsigned long long int	value;

	value = (unsigned long long int)nontypearg;
	if (value == 0)
		return (3);
	while (value != 0)
	{
		len++;
		value = value / 16;
	}
	return (len);
}

void	ft_printf_if_p_do_arr(void *nontypearg, char *arr)
{
	unsigned long long int	value;
	int						i;
	char					*hexbaselow;

	hexbaselow = "0123456789abcdef";
	i = 0;
	value = (unsigned long long int)nontypearg;
	if (value == 0)
	{
		arr[0] = '0';
		arr[1] = 'x';
		arr[2] = '0';
		arr[3] = '\0';
		return ;
	}
	while (value != 0)
	{
		arr[i] = hexbaselow[value % 16];
		value = value / 16;
		i++;
	}
	arr[i++] = 'x';
	arr[i++] = '0';
	arr[i] = '\0';
}

int	ft_printf_if_p_w(char *arr, int num, int len)
{
	while (--len >= 0)
	{
		if (ft_printf_w_typechar(arr[len], num) < 0)
		{
			free(arr);
			return (-1);
		}
	}
	free(arr);
	return (0);
}

int	ft_printf_if_p(void *nontypearg, int num)
{
	int		len;
	char	*arr;
	int		check;

	if (num < 0)
		return (num);
	len = ft_printf_if_p_len(nontypearg, 2);
	arr = malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
	{
		free(arr);
		return (-1);
	}
	ft_printf_if_p_do_arr(nontypearg, arr);
	len = ft_strlen(arr);
	num = num + len;
	check = ft_printf_if_p_w(arr, num, len);
	if (check < 0)
		return (-1);
	return (num);
}
