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
CFLAGS = -Wall -Werror -Wextra -ggdb3
LIBFT = ./libft/
LIB = -L./libft/
LIB += -lft
LIB += -lX11
LIB += -lXext
LIBMLX = -L./mlx/ -lmlx
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
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB) $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBHEADER)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

norme: $(SRC)
	norminette $^ $(HEADERS)*.h
