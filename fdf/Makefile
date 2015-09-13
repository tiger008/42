# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/06 23:50:57 by tperraut          #+#    #+#              #
#    Updated: 2015/04/08 01:15:14 by tperraut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ./libft/
HEADER = ./include/
LIBHEADER = ./libft/includes/
NAME = fdf
SRC = \
	src/ft_parser.c \
	src/main.c \
	src/ft_initgrid.c \
	src/get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd $(LIB) && $(MAKE) && cd .. && $(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIB) -lft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBHEADER)

clean:
	rm -f $(OBJ) && cd $(LIB) && $(MAKE) $@

fclean: clean
	rm -f $(NAME) && cd $(LIB) && $(MAKE) $@

re: fclean all

norme: $(SRC)
	norminette $^ $(HEADERS)*.h
