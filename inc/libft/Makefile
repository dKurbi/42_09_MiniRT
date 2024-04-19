# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 18:59:49 by iassambe          #+#    #+#              #
#    Updated: 2023/12/18 16:59:33 by iassambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIB_NAME = libft.h
LIB_FT_PRINTF_NAME = ft_printf.h
LIB_GNL_NAME = get_next_line.h

AR = ar rcs
RM = rm
MKDIR = mkdir -p
DIROBJS = objs/

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_FT_PRINTF = ft_printf.c ft_printf_if_c.c ft_printf_if_di.c ft_printf_if_p.c ft_printf_if_s.c ft_printf_if_u.c ft_printf_if_x.c ft_printf_w_typechar.c ft_printf_w_typestr.c
SRCS_GNL = get_next_line.c get_next_line_utils.c

OBJS = $(addprefix $(DIROBJS), $(SRCS:.c=.o))
OBJS_FT_PRINTF = $(addprefix $(DIROBJS), $(SRCS_FT_PRINTF:.c=.o))
OBJS_GNL = $(addprefix $(DIROBJS), $(SRCS_GNL:.c=.o))
OBJS_TOTAL = $(OBJS) $(OBJS_FT_PRINTF) $(OBJS_GNL)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(addprefix $(DIROBJS), $(BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_FT_PRINTF) $(OBJS_GNL)
	@$(AR) $(NAME) $(OBJS_TOTAL)

$(OBJS): $(DIROBJS)%.o: %.c $(LIB_NAME)
	@$(MKDIR) $(DIROBJS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_FT_PRINTF): $(DIROBJS)%.o: %.c $(LIB_FT_PRINTF_NAME)
	@$(MKDIR) $(DIROBJS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_GNL): $(DIROBJS)%.o: %.c $(LIB_GNL_NAME)
	@$(MKDIR) $(DIROBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf objs/

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

bonus: all $(OBJS) $(OBJS_FT_PRINTF) $(OBJS_GNL) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS_TOTAL) $(BONUS_OBJS)

$(BONUS_OBJS): $(DIROBJS)%.o: %.c $(LIBNAME)
	@$(MKDIR) $(DIROBJS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re
