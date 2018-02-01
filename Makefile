# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthorell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 20:03:46 by pthorell          #+#    #+#              #
#    Updated: 2018/01/30 19:15:16 by pthorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

HEADER = ./includes/

FLAG = -o $(NAME) -I $(HEADER) -Wall -Wextra -Werror

C_FILES = ./srcs/get_square.c \
		  ./srcs/print_square.c \
		  ./srcs/string_support.c \
		  ./srcs/file_manager.c \
		  ./srcs/main.c \
		  ./srcs/abort_error.c \
		  ./srcs/linked_list.c

all: $(NAME)

$(NAME): build

build:
	gcc $(FLAG) $(C_FILES)

clean:
	/bin/rm -rf $(wildcard *~)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
