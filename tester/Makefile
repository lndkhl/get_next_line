# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksefeane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/01 11:02:40 by ksefeane          #+#    #+#              #
#    Updated: 2019/07/01 13:53:05 by ksefeane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = app

SRC = ../get_next_line.c main.c

LIB = ../libft/libft.a

BUILD = gcc -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME): $(LIB)
	@$(BUILD) $(NAME) $(SRC) $(LIB)
	@echo "app created"

$(LIB):
	@make re -C ../libft

clean:
	@rm -rf $(NAME)
	@echo "app deleted"

fclean: clean

re: fclean all

.PHONY: clean fclean all re
