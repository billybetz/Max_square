# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbetz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/09 14:35:37 by bbetz             #+#    #+#              #
#    Updated: 2016/04/15 18:11:49 by bbetz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAG = -Wall -Werror -Wextra
INC = ./include
SRC = main.c \
	  ft_check_tetriminos.c \
	  ft_init_tetris.c \
	  ft_put_piece.c \
	  ft_put_size.c \
	  ft_solve.c \
	  ft_solve2.c \
	  ft_color.c	\

LIB = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC)  -I $(INC) $(LIB) $(CFLAG) $(SRC) -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
