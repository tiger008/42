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
LIBFT = ./libft/
LIB = -L./libft/
LIB += -lft
LIB += -L/usr/lib64
LIB += -lmlx
LIB += -lX11
LIB += -lXext
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
	cd $(LIBFT) && $(MAKE) && cd .. && $(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBHEADER)

clean:
	rm -f $(OBJ) && cd $(LIBFT) && $(MAKE) $@

fclean: clean
	rm -f $(NAME) && cd $(LIBFT) && $(MAKE) $@

re: fclean all

norme: $(SRC)
	norminette $^ $(HEADERS)*.h
