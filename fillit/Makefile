# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:54:33 by tperraut          #+#    #+#              #
#    Updated: 2015/11/29 04:45:29 by tperraut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ./libft
HEADERS = ./include
LIB_HEADER = $(LIB)/include
NAME = fillit
SRC = \
	  src/ft_trio.c \
	  src/ft_search.c \
	  src/parser.c \
	  src/fillit.c

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

norme: $(SRC)
	make norme -C $(LIB)
	norminette $^ $(HEADERS)libft.h

tclean:
	rm -f libft.so

retest: tclean test
