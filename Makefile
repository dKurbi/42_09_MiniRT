# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 20:00:30 by iassambe          #+#    #+#              #
#    Updated: 2024/04/19 20:37:30 by iassambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFTFLAGS = -Linc/libft -lft
MINILIBXFLAGS = -Linc/minilibx_ //aaaaaa
INCLUDEFLAGS = -Iinc/ -Iinc/libft/ -Iminilibx_ //aaaaa
DEPFLAGS = -MMD -MP

COLOR_GREEN = \033[0;32m
COLOR_RED = //aaaaa 
COLOR_RESET = \033[0m

DIR_SRC = src/
DIR_INC = inc/
DIR_OBJS = objs/
DIR_LIBFT = inc/libft/
DIR_MINILIBX = inc/minilibx_/  aaaaa

MKDIR = mkdir -p
RM = rm
MAKE = make
ECHO = echo

LIB_MINIRT = inc/minirt.h
COMPILED_LIBFT = libft.a
COMPILED_MINILIBX = inc/minilibx_ //aaaaaa

SRCS = 	minirt.c
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(COMPILED_LIBFT) $(COMPILED_MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(DEPFLAGS) $(LIBFTFLAGS) $(MINILIBXFLAGS) -o $(NAME)
	@$(ECHO) "MiniRT $(COLOR_GREEN)Compiled!$(COLOR_RESET)"

$(DIR_OBJS)%.o: $(DIR_SRC)%.c $(LIB_MINIRT) Makefile
	@$(MKDIR) $(DIR_OBJS)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDEFLAGS) -c $< -o $@

$(COMPILED_LIBFT):
	$(MAKE) -C $(DIR_LIBFT) bonus

$(COMPILED_MINILIBX): //aaaaaaa
	$(MAKE) -C $(DIR_READLINE)//aaaaaaaaaaaaaaaaaaaa

clean:
	$(MAKE) -C $(DIR_LIBFT) clean
	$(MAKE) -C $(DIR_MINILIBX) clean
	$(RM) -rf $(DIR_OBJS)

fclean: clean
	$(MAKE) -C $(DIR_LIBFT) fclean
	$(RM) -f $(NAME)

re: fclean all

r: re

norminette:
	norminette inc/libft/*.c inc/libft/*.h inc/*.h src/*.c

-include $(DEPS)

.PHONY: all clean fclean re
