# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:54:33 by tperraut          #+#    #+#              #
#*   Updated: 2016/05/19 23:38:02 by tperraut         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

##########
# TARGET #
##########

NAME = fdf

############
# COMPILER #
############

CC = clang
CFLAGS = -O3 -Werror -Wall -Wextra

#######
# LIB #
#######

LIB = -lft
LIB_DIR = ./libft
LIB_INC = -I $(LIB_DIR)/include

#######
# MLX #
#######

SYS = linux
FRAMEWORK =
ifneq (, $(findstring apple, $(shell $(CC) -dumpmachine)))
	SYS = mac
	FRAMEWORK = -framework OpenGL -framework AppKit
endif
MLX = -lmlx $(FRAMEWORK)
MLX_DIR = ./mlx-$(SYS)
MLX_INC = -I $(MLX_DIR)/include

##########
# HEADER #
##########

INC = -I ./include

##########
# SOURCE #
##########

SRC_DIR = ./src/
SRC_NAME = \
	ft_parser.c \
	ft_initgrid.c \
	get_next_line.c \
	main.c
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
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) -o $@ \
		$(OBJ) \
		$(INC) \
		$(LIB_INC) -L $(LIB_DIR) $(LIB) \
		$(MLX_INC) -L $(MLX_DIR) $(MLX)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(LIB_INC) $(INC) $(MLX_INC)

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
