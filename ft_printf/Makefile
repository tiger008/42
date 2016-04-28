# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:54:33 by tperraut          #+#    #+#              #
#    Updated: 2016/04/28 20:58:50 by tperraut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rc
HEADERS = ./include/
NAME = libftprintf.a
SRC = \
	src/ft_putstr.c \
	src/ft_strlen.c \
	src/ft_strdup.c \
	src/ft_itoa.c \
	src/ft_printf.c #\
	src/ft_strcmp.c \
	src/ft_putchar.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme: $(SRC)
	norminette $^ $(HEADERS)
