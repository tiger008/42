# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:54:33 by tperraut          #+#    #+#              #
#*   Updated: 2016/05/25 20:28:01 by tperraut         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

##########
# TARGET #
##########

NAME = libft.a

############
# COMPILER #
############

CC = clang
CFLAGS = -O3 -Werror -Wall -Wextra
LIB = ar rc

##########
# HEADER #
##########

INC_DIR = ./include/
INC_NAME = libft.h
INCLUDE = $(addprefix $(INC_DIR), $(INC_NAME))
INC = -I $(INC_DIR)

##########
# SOURCE #
##########

SRC_DIR = ./src/
SRC_NAME = \
	ft_delsplit.c \
	ft_tablen.c \
	ft_free.c \
	ft_isreturn.c \
	ft_isblank.c \
	ft_abs.c \
	ft_error.c \
	ft_sqrt.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_memccpy.c \
	ft_strncpy.c \
	ft_strcmp.c \
	ft_strstr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strlcat.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_strsplit.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

##########
# OBJECT #
##########

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

#########
# RULES #
#########

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $@ $^
	ranlib $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
