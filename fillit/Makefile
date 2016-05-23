# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:54:33 by tperraut          #+#    #+#              #
#    Updated: 2016/05/23 10:40:00 by tperraut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ./libft
HEADERS = ./include
LIB_HEADER = $(LIB)/include
NAME = fillit
SRC = \
	  src/ft_accept.c \
	  src/ft_resolve.c \
	  src/ft_affiche.c \
	  src/ft_add_trio.c \
	  src/ft_remove_trio.c \
	  src/ft_free_mat.c \
	  src/ft_create_mat.c \
	  src/ft_putpt.c \
	  src/ft_pset.c \
	  src/parser.c \
	  src/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB) -lft -I $(HEADERS) -I $(LIB_HEADER)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADERS) -I $(LIB_HEADER)

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all
