/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_minirt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:31:50 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/25 19:51:55 by iassambe         ###   ########.fr       */
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
#  define KEY_ENTER 36
#  define KEY_DELETE 51
#  define KEY_SPACE 49
#  define KEY_ARROW_UP 126
#  define KEY_ARROW_DOWN 125
#  define KEY_ARROW_LEFT 123
#  define KEY_ARROW_RIGHT 124
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_C 8
# endif

//masks mlx
# ifdef __linux__
#  define MASK_DESTROY 1
# else
#  define MASK_DESTROY 0
# endif

//other defines
# define ERROR 1
# define SPACE 32
# define FREE_MLX 1
# define NO_FREE_MLX 0

#endif