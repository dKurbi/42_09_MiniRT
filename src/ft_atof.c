/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:31:57 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/04/27 17:40:17 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	initnum(const char *str, int *sign, float *number, int *posdot)
{
	int	i;

	*number = 0;
	i = 0;
	*sign = 1;
	*posdot = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		*sign = -1;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

static int	is_too_long(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			len++;
		i++;
	}
	if (str && len < 14)
		return (0);
	return (1);
}

static int	postdotmanage(int *posdot)
{
	if (*posdot > 0)
		return (1);
	else
		*posdot = 1;
	return (0);
}
//atoi but to float
float	ft_atof(char *str)
{
	int		i;
	float	n;
	int		sign;
	int		posdot;

	i = initnum(str, &sign, &n, &posdot);
	if (is_too_long((char *) str))
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			n = (n * 10) + (str[i] - '0');
			if (posdot > 0)
				posdot++;
		}
		else if ((str[i] == '.' || str[i] == ',') && ft_isdigit(str[i + 1]))
			if (postdotmanage(&posdot))
				return (0);
		i++;
	}
	return (sign * (n / (pow(10, posdot))));
}