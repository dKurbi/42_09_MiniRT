/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:32:28 by iassambe          #+#    #+#             */
/*   Updated: 2024/05/07 21:25:52 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//check if after checking all, there is empty or only spaces
int	empty_after_line(char *line, int i_provide)
{
	i_provide = skip_spaces(line, i_provide);
	if (i_provide >= (int)ft_strlen(line))
		return (1);
	return (0);
}

int	check_is_a_rgb_create(char *str, int *i, int i_copy, t_rgb *color)
{
	char	*number;
	char	**split;

	number = ft_substr(str, *i, i_copy - *i);
	if (!number)
		return (1);
	split = ft_split(number, ',');
	free(number);
	if (!split)
		return (1);
	if (len_split(split) != 3)
		return (free_double_str(&split), 1);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	free_double_str(&split);
	if (rgb_limit(color->r, color->g, color->b) > 0)
		return (1);
	return (0);
}
