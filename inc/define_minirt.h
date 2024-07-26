/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_minirt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:31:50 by iassambe          #+#    #+#             */
/*   Updated: 2024/07/26 19:38:42 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_MINIRT_H
# define DEFINE_MINIRT_H

# include "./minirt.h"

//error strings
# define ERR_MALLOC "memory allocation error (*malloc)\n"
# define ERR_EXTENSION "file doesn't have *.rt extension\n"
# define ERR_INC_ARGS "incorrect arguments passed\n"
# define ERR_EMPTY "the file is empty\n"
# define ERR_INIT_SCENE "error initializing scene\n"
# define ERR_VALUE_NUM "values in line are not numbers\n"
# define ERR_VALUE_STR "only numbers in line, no string arguments\n"
# define ERR_VALUE_MUCH "too much values in a scene description\n"
# define ERR_VALUE_SYNTAX "syntax of values is incorrect\n"
# define ERR_NOT_ENOUGH "not enough values in a scene description\n"
# define ERR_VALUE_NOT_SCENE "string is not a one of scene descriptions\n"
# define ERR_VALUE_INCOR_PASS "value passed incorrectly in a line\n"
# define ERR_NOT_FLOAT "number or string is not a float\n"
# define ERR_RANGE "value is out of range\n"
# define ERR_RGB "values are not RGB\n"
# define ERR_NOT_VECTOR "values are not vectors\n"
# define ERR_VECTOR_RANGE "values in vector are out of range\n"
# define ERR_A_C_L "file doesn't have only 1 ambient light (A), \
1 camera (C) and 1 light (L)\n"

//normal strings
# define STR_MINIRT "miniRT: "
# define STR_AMBIENT "ambient light"
# define STR_CAMERA "camera"
# define STR_LIGHT "light"
# define STR_SPHERE "sphere"
# define STR_PLANE "plane"
# define STR_CYL "cylinder"
# define STR_ERR_OCCURR "Error occurred in line: "

//pixels for mlx window (Linux/Mac)
# ifdef __linux__
#  define WIN_X 1280
#  define WIN_Y 920
# else
#  define WIN_X 1920
#  define WIN_Y 1200
# endif

//events mlx
# define EV_KEY 2
# define EV_DESTROY 17

//keys mlx
# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_ENTER 65293
#  define KEY_DELETE 65288
#  define KEY_SPACE 32
#  define KEY_PLUS 65451
#  define KEY_MINUS 65453
#  define KEY_ARROW_UP 65362
#  define KEY_ARROW_DOWN 65364
#  define KEY_ARROW_LEFT 65361
#  define KEY_ARROW_RIGHT 65363
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_B 98
#  define KEY_V 118
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_Z 122
#  define KEY_X 120
#  define KEY_C 99
#  define KEY_R 114
#  define KEY_T 116
# else
#  define KEY_ESC 53
#  define KEY_ENTER 36
#  define KEY_DELETE 51
#  define KEY_SPACE 49
#  define KEY_PLUS 69
#  define KEY_MINUS 78
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
#  define KEY_R 15
#  define KEY_T 17


# endif

//mouse control mlx
# ifdef __linux__
#  define MOUSE_LEFT 1
#  define MOUSE_RIGHT 3
#  define MOUSE_MIDDLE 2
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
# else
#  define MOUSE_LEFT 1
#  define MOUSE_RIGHT 2
#  define MOUSE_MIDDLE 3
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
# endif

//masks mlx
# ifdef __linux__
#  define MASK_DESTROY 1
# else
#  define MASK_DESTROY 0
# endif

//shapes intersection
# define NO_INTER 0
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

//3.14 not defined in Linux
# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif
#define EPSILON 1e-2

//other defines
# define ERROR 1
# define SPACE 32
# define POINT 46
# define FREE_MLX 1
# define NO_FREE_MLX 0

#endif