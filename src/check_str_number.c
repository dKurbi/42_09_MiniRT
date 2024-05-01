/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:58:49 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/01 03:54:35 by iassambe         ###   ########.fr       */
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

//checking if float passed correctly, set *i to the next spaces
//save float in *fl ||| 1 - incorrect, 0 - correct
int	check_is_a_float(char *str, int *i, double *fl)
{
	int		end;
	int		point;
	char	*number;

	end = *i;
	point = 0;
	if (!str || str[end] == '.' || len_str(str, i) > 15 || \
	(str[end] == '-' && \
	(!str[end + 1] || if_space(str[end + 1]) || str[end + 1] == '.')))
		return (1);
	if (str[end] == '-')
		end++;
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
	number = ft_substr(str, *i, end - *i);
	if (!number)
		return (1);
	*fl = ft_atof(number);
	free(number);
	*i = end;
	return (0);
}

//check if we have a vector, without range limits
int	check_is_a_vector(char *str, int *i, t_vector *vector)
{
	int		i_copy;
	int		coma_count;
	int		point_count;
	char	*number;
	char	**split;
	int		i_for_float;
	
	i_for_float = 0;
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
		if (str[i_copy] == '.')
			point_count++;
		else if (str[i_copy] == ',')
			coma_count++;
		else if (!ft_isdigit(str[i_copy]) && str[i_copy] != '-')
			return (1);
		i_copy++;
	}
	number = ft_substr(str, *i, i_copy - *i);
	split = ft_split(number, ',');
	if (!number || !split || coma_count != 2 || point_count >= 4)
		return (free_str(&number), free_double_str(&split), 1);
	free(number);
	if (check_is_a_float(split[0], &i_for_float, &vector->x))
		return (free_double_str(&split), 1);
	i_for_float = 0;
	if (check_is_a_float(split[1], &i_for_float, &vector->y))
		return (free_double_str(&split), 1);
	i_for_float = 0;
	if (check_is_a_float(split[2], &i_for_float, &vector->z))
		return (free_double_str(&split), 1);
	free_double_str(&split);
	return (0);
}

int	check_is_a_rgb(char *str, int *i, t_rgb *color)
{
	int		i_copy;
	int		coma_count;
	char	*number;
	char	**split;

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
	printf("checkout seg\n");
	number = ft_substr(str, *i, i_copy - *i);
	split = ft_split(number, ',');
	if (!number || !split)
		return (free_str(&number), 1);
	free(number);
	if (len_split(split) != 3 || coma_count != 2)
		return (free_double_str(&split), 1);
	printf("checkout seg\n");
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	free_double_str(&split);
	printf("checkout seg\n");
	if (rgb_limit(color->r, color->g, color->b) > 0)
		return (1);
	printf("checkout seg\n");
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
