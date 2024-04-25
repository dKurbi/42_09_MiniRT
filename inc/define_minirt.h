/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_minirt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:31:50 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 17:34:05 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_MINIRT_H
# define DEFINE_MINIRT_H

# include "./minirt.h"

//error strings
# define ERR_EXTENSION "file doesn't have *.rt extension\n"
# define ERR_INC_ARGS "incorrect arguments passed\n"
# define ERR_EMPTY "the file is empty\n"
# define ERR_VALUE "values in scene are not passed correctly\n"

//normal strings
# define STR_MINIRT "miniRT: "

//pixels for mlx window (Linux/Mac)
# ifdef __linux__
#  define WIN_X 1280
#  define WIN_Y 720
# else
#  define WIN_X 1920
#  define WIN_Y 1200
# endif

//events
# define EV_KEY 2
# define EV_DESTROY 17
# define EV_MOUSE 21322//add int later because i dont remember

//keys
# ifdef __linux__
#  define KEY_ESC 65307
# else
#  define KEY_ESC 53
# endif

//masks mlx

//other defines
# define ERROR 1
# define SPACE 32
# define FREE_MLX 1
# define NO_FREE_MLX 0

#endif