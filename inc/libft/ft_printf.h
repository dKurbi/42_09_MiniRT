/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:48:54 by iassambe          #+#    #+#             */
/*   Updated: 2023/08/01 18:13:21 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft.h"

int	ft_printf_w_typechar(int const s, int num);
int	ft_printf_w_typestr(char const *s, int num);

int	ft_printf_if_c(int numarg, int num);
int	ft_printf_if_s(char *sarg, int num);
int	ft_printf_if_p(void *nontypearg, int num);
int	ft_printf_if_di(int numarg, int num);
int	ft_printf_if_u(unsigned int uarg, int num);
int	ft_printf_if_x(unsigned int uarg, int num, char *base);

int	ft_printf(char const *s, ...);

#endif
