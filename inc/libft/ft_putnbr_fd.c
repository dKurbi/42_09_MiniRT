/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:17:18 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/16 20:08:59 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_fdifneg(int n, int fd)
{
	int	dos;

	write(fd, "-", 1);
	if (n == -2147483648)
	{
		dos = 50;
		write(fd, &dos, 1);
		n = 147483648;
		return (n);
	}
	n = -1 * n;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	ncopy;

	if (n < 0)
		n = ft_putnbr_fdifneg(n, fd);
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		n = n % 10;
	}
	if (n >= 0 && n <= 9)
	{
		ncopy = n + 48;
		write(fd, &ncopy, 1);
	}
}
