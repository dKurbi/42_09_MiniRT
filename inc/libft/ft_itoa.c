/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:37:04 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/18 15:15:09 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	len;
	int	ncopy;

	ncopy = n;
	len = 0;
	if (ncopy < 0)
	{
		if (ncopy == -2147483648)
			return (11);
		ncopy = -1 * ncopy;
		len = 1;
	}
	if (ncopy == 0)
		return (1);
	while (0 < ncopy)
	{
		len++;
		ncopy = ncopy / 10;
	}
	return (len);
}

static char	*ft_itoa_turn(int n, char *arr, int len)
{
	if (n >= 10)
	{
		arr = ft_itoa_turn(n / 10, arr, len - 1);
	}
	arr[len] = n % 10 + '0';
	arr[len + 1] = '\0';
	return (arr);
}

static char	*ft_itoa_turnifneg(int n, char *arr, int len)
{
	arr[0] = '-';
	if (n == -2147483648)
	{
		arr[1] = '2';
		n = 147483648;
		arr = ft_itoa_turn(n, arr, len - 1);
		return (arr);
	}
	n = -1 * n;
	arr = ft_itoa_turn(n, arr, len - 1);
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;

	len = ft_itoa_len(n);
	arr = (char *) malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	if (n == 0)
	{
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	if (n < 0)
		arr = ft_itoa_turnifneg(n, arr, len);
	else
		arr = ft_itoa_turn(n, arr, len - 1);
	return (arr);
}
