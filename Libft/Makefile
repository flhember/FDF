# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flhember <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 18:09:39 by flhember          #+#    #+#              #
#    Updated: 2019/05/08 15:03:22 by flhember         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC_FILES = ft_strlen.c 	  		\
			ft_strcpy.c 	  		\
			ft_strdup.c 	  		\
			ft_strncpy.c	  		\
			ft_strcat.c	  			\
			ft_strncat.c	  		\
			ft_strlcat.c	 	 	\
			ft_putchar.c	  		\
			ft_putstr.c	  			\
			ft_strchr.c	  			\
			ft_strrchr.c	  		\
			ft_strstr.c				\
			ft_strnstr.c	  		\
			ft_strcmp.c	  			\
			ft_strncmp.c	  		\
			ft_atoi.c		  		\
			ft_isalpha.c	  		\
			ft_isdigit.c	  		\
			ft_isalnum.c	  		\
			ft_isascii.c	  		\
			ft_isprint.c	  		\
			ft_toupper.c	  		\
			ft_tolower.c	  		\
			ft_memset.c	  			\
			ft_bzero.c	  			\
			ft_memcpy.c	  			\
			ft_memccpy.c	  		\
			ft_memmove.c	  		\
			ft_memchr.c	  			\
			ft_memcmp.c	  			\
			ft_memalloc.c	  		\
			ft_memdel.c	  			\
			ft_strnew.c	  			\
			ft_strdel.c	  			\
			ft_strclr.c	  			\
			ft_striter.c	  		\
			ft_striteri.c	  		\
			ft_strmap.c	  			\
			ft_strmapi.c	  		\
			ft_strequ.c	  			\
			ft_strnequ.c	  		\
			ft_strsub.c	  			\
			ft_strjoin.c	  		\
			ft_strtrim.c	  		\
			ft_putendl.c	  		\
			ft_putnbr.c	  			\
			ft_putnbr_fd.c  		\
			ft_putchar_fd.c 		\
			ft_putstr_fd.c  		\
			ft_putendl_fd.c 		\
			ft_strsplit.c	  		\
			ft_itoa.c		  		\
			ft_lstnew.c	  			\
			get_next_line.c			\
			ft_lstdelone.c  		\
			ft_lstdel.c	  			\
			ft_lstadd.c	  			\
			ft_lstiter.c   			\
			ft_lstmap.c	 			\
			ft_print_list.c			\
			ft_swap.c		  		\
			ft_str_is_lowercase.c	\
			ft_str_is_uppercase.c	\
			ft_strjoinfree.c		\
			ft_intlen.c				\
			ft_lltoa.c				\
			ft_strnewspace.c		\
			ft_ultoa_base.c			\
			ft_ultoa_base_big.c		\
			ft_pow.c				\
			ft_free_tab_int.c		\
			ft_str_rev.c			\
			ft_strnewnull.c			\
			ft_clean_str.c

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_PATH)
	@echo "\033[40mCompilation of \033[1m$(notdir $<)\033[0m \033[32mdone.\033[0m"

$(NAME): $(OBJ_PATH) $(OBJ_EXEC)
	@ar rc $(NAME) $(OBJ_EXEC)
	@ranlib $(NAME)
	@echo "\033[1;32m$(notdir $(NAME))\033[1;0m\033[32m created.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: clean fclean
