# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 20:00:30 by iassambe          #+#    #+#              #
#    Updated: 2024/04/21 20:20:06 by iassambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

UNAME_S := $(shell uname -s)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3
LIBFTFLAGS = -Linc/libft -lft

COMPILEFLAGS = 
MINILIBXFLAGS = 
DIR_MINILIBX = 

MACMINILIBXFLAGS = -Iminilibx-mac -Linc/minilibx-mac -lmlx
MACCOMPILEFLAGS = -framework OpenGL -framework AppKit
MAC_DIR_MINILIBX = inc/minilibx-mac/

LINUXMINILIBXFLAGS = -Iminilibx-linux -Linc/minilibx-linux -lmlx
LINUXCOMPILEFLAGS = -X11 #etc
LINUX_DIR_MINILIBX = inc/minilibx-linux/

INCLUDEFLAGS = -Iinc/ -Iinc/libft/
DEPFLAGS = -MMD -MP

ifeq ($(UNAME_S),Linux)
    COMPILEFLAGS += $(LINUXCOMPILEFLAGS)
	MINILIBXFLAGS += $(LINUXMINILIBXFLAGS)
	DIR_MINILIBX += $(LINUX_DIR_MINILIBX)
else ifeq ($(UNAME_S),Darwin)
    COMPILEFLAGS += $(MACCOMPILEFLAGS)
	MINILIBXFLAGS += $(MACMINILIBXFLAGS)
	DIR_MINILIBX += $(MAC_DIR_MINILIBX)
else
    $(error Not valid OS: $(UNAME_S))
endif

COLOR_GREEN = \033[0;32m
COLOR_RED = \033[0;31m
COLOR_BOLD_RED = \033[1;31m
COLOR_RESET = \033[0m

DIR_SRC = src/
DIR_INC = inc/
DIR_OBJS = objs/
DIR_LIBFT = inc/libft/

MKDIR = mkdir -p
RM = rm
MAKE = make
ECHO = echo

LIB_MINIRT = inc/minirt.h
LIB_STRUCT_MINIRT = inc/struct_minirt.h
LIB_DEFINE_MINIRT = inc/define_minirt.h
COMPILED_LIBFT = libft.a
COMPILED_MINILIBX = libmlx.a

SRCS = 	minirt.c check_file.c error.c free.c struct.c
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(COMPILED_LIBFT) $(COMPILED_MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(DEPFLAGS) $(LIBFTFLAGS) $(MINILIBXFLAGS) $(COMPILEFLAGS) -o $(NAME)
	@$(ECHO) "MiniRT $(COLOR_GREEN)Compiled!$(COLOR_RESET)"

$(DIR_OBJS)%.o: $(DIR_SRC)%.c $(LIB_MINIRT) $(LIB_STRUCT_MINIRT) $(LIB_DEFINE_MINIRT) Makefile
	@$(MKDIR) $(DIR_OBJS)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDEFLAGS) -c $< -o $@

$(COMPILED_LIBFT):
	$(MAKE) -C $(DIR_LIBFT) bonus

$(COMPILED_MINILIBX):
	$(MAKE) -C $(DIR_MINILIBX)

clean:
	@$(MAKE) -C $(DIR_LIBFT) clean
	@$(MAKE) -C $(DIR_MINILIBX) clean
	@$(RM) -rf $(DIR_OBJS)
	@$(ECHO) "miniRT $(COLOR_RED)Cleaned!$(COLOR_RESET)"

fclean: clean
	@$(MAKE) -C $(DIR_LIBFT) fclean
	@$(RM) -f $(NAME)
	@$(ECHO) "miniRT $(COLOR_BOLD_RED)FCleaned!$(COLOR_RESET)"

re: fclean all

r: re

fcle: fclean

fc: fclean

fcl: fclean

norminette:
	norminette inc/libft/*.c inc/libft/*.h inc/*.h src/*.c

-include $(DEPS)

.PHONY: all clean fclean re
