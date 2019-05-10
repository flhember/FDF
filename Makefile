# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flhember <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 15:51:59 by flhember          #+#    #+#              #
#    Updated: 2019/05/09 12:46:32 by flhember         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
FLAGS = -fsanitize=address -Wall -Wextra -Werror

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
LIB_PATH = ./Libft/
MINI_PATH = ./minilibx_macos/
INC_PATH = ./includes/

FRAMEWORK = -lmlx -framework OpenGL -framework Appkit

SRC_FILES = main.c			\
			ft_free.c		\
			ft_parcing.c	\
			ft_fdf.c

INC_FILES = fdf.h

LIB_FILES = libft.a
MINI_FILES = libmlx.a

MINI = $(addprefix $(MINI_PATH), $(MINI_FILES))
LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))
LIB_HEADER = $(addprefix $(LIB_PATH), $(INC_PATH))

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_HEADER)
	@echo "\033[40mCompilation of \033[1m$(notdir $<)\033[0m \033[32mdone.\033[0m"

$(LIB):
	@make -C $(LIB_PATH)
	@make -C $(MINI_PATH) 

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC)
	@$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) $(MINI) -o $(NAME) -I $(INC_PATH) -I $(LIB_HEADER) $(FRAMEWORK)
	@echo "\033[1;32m$(notdir $(NAME))\033[1;0m\033[32m created.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@make clean -C $(MINI_PATH)
	@/bin/rm -rf $(NAME)
	@echo "\033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
