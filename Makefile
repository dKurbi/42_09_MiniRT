# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 20:00:30 by iassambe          #+#    #+#              #
#    Updated: 2024/05/07 22:16:02 by iassambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Executable program
NAME = minirt

#	Get current OS
UNAME_S := $(shell uname -s)

#	Compile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3 #-fsanitize=address
LIBFTFLAGS = -Linc/libft -lft
INCLUDEFLAGS = -Iinc/ -Iinc/libft/
DEPFLAGS = -MMD -MP

#	Decide for compile, detect OS and add
MINILIBXFLAGS = 
MINILIBXCOMPILEFLAGS = 
DIR_MINILIBX = 

#	Variables for Mac (Darwin)
MACMINILIBXFLAGS = -Iminilibx-mac/ -Linc/minilibx-mac -lmlx
MACMINILIBXCOMPILEFLAGS = -framework OpenGL -framework AppKit
MAC_DIR_MINILIBX = inc/minilibx-mac/

#	Variables for Linux
LINUXMINILIBXFLAGS = -Iminilibx-linux/ -Linc/minilibx-linux -lmlx
LINUXMINILIBXCOMPILEFLAGS = -L/usr/lib -lX11 -lm -lz -lXext
LINUX_DIR_MINILIBX = inc/minilibx-linux/

#	Assigning rules for OS compile
ifeq ($(UNAME_S),Linux)
    MINILIBXCOMPILEFLAGS += $(LINUXMINILIBXCOMPILEFLAGS)
	MINILIBXFLAGS += $(LINUXMINILIBXFLAGS)
	DIR_MINILIBX += $(LINUX_DIR_MINILIBX)
else ifeq ($(UNAME_S),Darwin)
    MINILIBXCOMPILEFLAGS += $(MACMINILIBXCOMPILEFLAGS)
	MINILIBXFLAGS += $(MACMINILIBXFLAGS)
	DIR_MINILIBX += $(MAC_DIR_MINILIBX)
else
    $(error Not valid OS: $(UNAME_S))
endif

#	Colors
COLOR_GREEN = \033[0;32m
COLOR_RED = \033[0;31m
COLOR_YELLOW = \033[0;93m
COLOR_LIGHT_RED = \033[0;91m
COLOR_BOLD_WHITE = \033[1;97m
COLOR_RESET = \033[0m

#	Directories
DIR_SRC = src/
DIR_INC = inc/
DIR_OBJS = objs/
DIR_LIBFT = inc/libft/

#	Shell commands
MKDIR = mkdir -p
RM = rm
MAKE = make
ECHO = echo

#	Files .h and .a
LIB_MINIRT = inc/minirt.h
LIB_STRUCT_MINIRT = inc/struct_minirt.h
LIB_DEFINE_MINIRT = inc/define_minirt.h
COMPILED_LIBFT = libft.a
COMPILED_MINILIBX = libmlx.a

#	Files .c and .o
SRCS = 	minirt.c check_file.c error.c free.c struct.c utils.c utils_mlx.c \
		event.c check.c ft_atof.c add_scene_capital.c add_scene_lower.c \
		check_str_number.c utils_check.c free_struct_lst.c utils_check_2.c \
		add_struct_figure.c
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

#	Compiling process
all: $(NAME)

$(NAME): $(COMPILED_LIBFT) $(COMPILED_MINILIBX) $(DIR_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEPFLAGS) $(LIBFTFLAGS) $(MINILIBXFLAGS) $(MINILIBXCOMPILEFLAGS) -o $(NAME)
	@$(ECHO) "$(COLOR_BOLD_WHITE)miniRT $(COLOR_GREEN)Compiled!$(COLOR_RESET)"

$(DIR_OBJS):
	@$(MKDIR) $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRC)%.c $(LIB_MINIRT) $(LIB_STRUCT_MINIRT) $(LIB_DEFINE_MINIRT) Makefile
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDEFLAGS) -c $< -o $@

$(COMPILED_LIBFT):
	$(MAKE) -C $(DIR_LIBFT) bonus

$(COMPILED_MINILIBX):
	$(MAKE) -C $(DIR_MINILIBX)

clean:
	@$(MAKE) -C $(DIR_LIBFT) clean
	@$(MAKE) -C $(DIR_MINILIBX) clean
	@$(RM) -rf $(DIR_OBJS)
	@$(ECHO) "$(COLOR_BOLD_WHITE)miniRT $(COLOR_LIGHT_RED)Cleaned!$(COLOR_RESET)"

fclean: clean
	@$(MAKE) -C $(DIR_LIBFT) fclean
	@$(RM) -f $(NAME)
	@$(ECHO) "$(COLOR_BOLD_WHITE)miniRT $(COLOR_RED)FCleaned!$(COLOR_RESET)"

re: fclean all

#	Additional compiling rules
r: re

fcle: fclean

fc: fclean

fcl: fclean

norminette:
	norminette inc/libft/*.c inc/libft/*.h inc/*.h src/*.c

norm: norminette

n: norminette

-include $(DEPS)

.PHONY: all clean fclean re
