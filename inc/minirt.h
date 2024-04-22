/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:35:34 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/22 05:36:23 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

# include "./struct_minirt.h"
# include "./define_minirt.h"
# include "./libft/libft.h"

# ifndef __linux__
#  include "./minilibx-mac/mlx.h"
# else
#  include "./minilibx-linux/mlx.h"
# endif

//check_file.c
int		check_file(t_rt rt);

//error.c
int		print_error_exit(t_rt rt, char *s_err, int status);

//free.c
char	*free_str(char **s);
void	free_rt(t_rt *rt);

//minirt.c

//struct.c
void	rtnew(t_rt *rt, int ac, char **av);

#endif
