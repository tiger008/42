# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/29 17:36:12 by mvaude            #+#    #+#              #
#    Updated: 2015/01/08 11:15:56 by tperraut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moulinette
RENDU_PATH = $(shell awk -F "=" '/LIBFT_PATH/ {print $$2}' ../../config.ini)

all: $(NAME)

$(NAME):
	@gcc -fPIC -Wall -Werror -Wextra -c $(RENDU_PATH)/*.c
	@gcc -fPIC -Werror -Wall -Wextra -shared -o libft.so *.o
	./Mouli-nator

clean:
	@rm -rf *.o
	@rm -rf libft.so

re: clean all
