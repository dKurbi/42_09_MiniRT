/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_minirt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:31:50 by iassambe          #+#    #+#             */
/*   Updated: 2024/04/24 18:31:44 by iassambe         ###   ########.fr       */
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

//pixels for window
# define WIN_X 1480
# define WIN_Y 1260

//events
# define EV_KEY 2
# define EV_DESTROY 17

//other defines
# define ERROR 1
# define SPACE 32

#endif