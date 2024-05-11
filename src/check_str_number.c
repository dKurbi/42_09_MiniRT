/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:58:49 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/09 05:29:06 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//checking if float passed correctly, set *i to the next spaces
//save float in *fl ||| 1 - incorrect, 0 - correct
int	check_is_a_float(char *str, int *i, double *fl)
{
	int		end;
	int		point;

	end = *i;
	point = 0;
	if (check_is_a_float_first_check(str, i, &end))
		return (1);
	while (str[end] && (if_space(str[end]) == 0))
	{
		if (ft_isdigit(str[end]) || (str[end] == '.' && point < 2))
		{
			if (str[end] == '.')
				point++;
			end++;
		}
		else
			return (1);
	}
	if (str[end - 1] == '.' || point > 1)
		return (1);
	if (check_is_a_float_add(str, i, end, fl))
		return (1);
	return (0);
}

//check if we have a vector, without range limits
int	check_is_a_vector(char *str, int *i, t_vector *vector)
{
	int	i_copy;
	int	coma_count;
	int	point_count;

	coma_count = 0;
	point_count = 0;
	i_copy = *i;
	while (str[i_copy] && (if_space(str[i_copy]) == 0))
	{
		if (str[i_copy] == '.' || str[i_copy] == ',')
		{
			if (i_copy - 1 >= 0 && \
				(str[i_copy - 1] == '.' || str[i_copy - 1] == ','))
				return (1);
		}
		if (check_is_a_vector_loop(str, i_copy, &point_count, &coma_count))
			return (1);
		i_copy++;
	}
	if (coma_count != 2 || point_count >= 4 || \
		check_is_a_vector_add(str, i, vector, i_copy))
		return (1);
	return (0);
}

//check if only ints and if in range
int	check_is_a_rgb(char *str, int *i, t_rgb *color)
{
	int		i_copy;
	int		coma_count;

	coma_count = 0;
	i_copy = *i;
	while (str[i_copy] && (if_space(str[i_copy]) == 0))
	{
		if (str[i_copy] == ',')
		{
			if ((i_copy - 1) >= 0 && str[i_copy - 1] == ',')
				return (1);
			coma_count++;
		}
		else if (!ft_isdigit(str[i_copy]) || coma_count > 2)
			return (1);
		i_copy++;
	}
	if (coma_count != 2 || check_is_a_rgb_create(str, i, i_copy, color))
		return (1);
	*i = i_copy;
	return (0);
}

//check if we have a vector, WITH range limits
//vector limits: -1 , 1
int	check_is_a_vector_range(char *str, int *i, t_vector *vec)
{
	if (check_is_a_vector(str, i, vec))
		return (1);
	if (!(vec->x >= -1 && vec->x <= 1) || \
		!(vec->y >= -1 && vec->y <= 1) || \
		!(vec->z >= -1 && vec->z <= 1))
		return (1);
	return (0);
}
