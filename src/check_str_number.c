/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:23:24 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/04/28 19:30:224 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//check if we have a vector, without range limits
int check_is_a_vector(char *str, int *i, t_vector *vector)
{
	(void) str;
    (void) *i;
    (void) *vector;
	return (0);
}

// 1 si es no es float 0 si es float
int	check_is_a_float(char *str, int *i, float *fl)
{
	int		end;
    int		point;
    char	*number;
    
    end = *i;
    point = 0;
    if (!str || str[end] == '.')
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
    if (str[end - 1] == '.')
        return (1);
    number = ft_substr(str, *i, end - *i);
    printf("el numero para hacer float es %s\n", number);
	if (!number)
		return (1);
    *fl = ft_atof(number);
	free(number);
	*i = end;
    return (0);
}   


int check_is_rgb(char *line, int *i, t_rgb *color)
{
	int	i_copy;
	int	coma_count;

    (void) color;
	coma_count = 0;
	i_copy = *i;
	while (line[i_copy] && (if_space(line[i_copy]) == 0))
	{
		if (line[i_copy] == ',')
			coma_count++;

		i_copy++;
	}
	
	return (0);
}

//check if we have a vector, WITH range limits
int	check_is_a_vector_range(char *line, int *i, t_vector *vec)
{
    (void) line;
    (void) *i;
    (void) *vec;
	return (0);
}