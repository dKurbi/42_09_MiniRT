/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:05:15 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/07 21:00:20 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// 1 si es no es float 0 si es float
static int	len_str(char *str, int *i)
{
	int	len;
	int	j;

	j = *i;
	len = 0;
	while (str[j] && !(str[j] == ' ' || str[j] == '\t'))
	{
		j++;
		len++;
	}
	return (len);
}

int	check_is_a_vector_loop(char *str, int i_c, int *point, int *coma)
{
	if (str[i_c] == '.')
		(*point)++;
	else if (str[i_c] == ',')
		(*coma)++;
	else if (!ft_isdigit(str[i_c]) && str[i_c] != '-')
		return (1);
	return (0);
}

int	check_is_a_vector_add(char *str, int *i, t_vector *vec, int i_cop)
{
	char	*number;
	char	**split;
	int		i_for_float;

	number = ft_substr(str, *i, i_cop - *i);
	if (!number)
		return (1);
	split = ft_split(number, ',');
	free_str(&number);
	if (!split)
		return (1);
	i_for_float = 0;
	if (check_is_a_float(split[0], &i_for_float, &vec->x))
		return (free_double_str(&split), 1);
	i_for_float = 0;
	if (check_is_a_float(split[1], &i_for_float, &vec->y))
		return (free_double_str(&split), 1);
	i_for_float = 0;
	if (check_is_a_float(split[2], &i_for_float, &vec->z))
		return (free_double_str(&split), 1);
	free_double_str(&split);
	*i = i_cop;
	return (0);
}

int	check_is_a_float_first_check(char *str, int *i, int *end)
{
	if (!str || str[*end] == '.' || len_str(str, i) > 15 || \
	(str[*end] == '-' && \
	(!str[*end + 1] || if_space(str[*end + 1]) || str[*end + 1] == '.')))
		return (1);
	if (str[*end] == '-')
		(*end)++;
	return (0);
}

int	check_is_a_float_add(char *str, int *i, int end, double *fl)
{
	char	*number;

	number = ft_substr(str, *i, end - *i);
	if (!number)
		return (1);
	*fl = ft_atof(number);
	free(number);
	*i = end;
	return (0);
}
