# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 14:40:09 by lnkambul          #+#    #+#              #
#    Updated: 2019/07/10 13:36:31 by lnkambul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = test
PESKY = *.h.gch
CFILE1 = get_next_line.c 
CFILE2 = main.c
O1 = get_next_line.o
O2 = main.o

RM = rm -f

all: $(NAME)

$(NAME): 
	 $(CC) $(CFLAGS)  $(O1) $(O2) $(INCLUDE) -o $(NAME)

$(O1):
	$(CC) $(CFLAGS) -c $(CFILE1)

$(O2):
	$(CC) $(CFLAGS) -c $(CFILE2)

clean:
	$(RM) $(OBJECTS)

fclean:
	$(RM) $(OBJECTS) $(NAME) $(PESKY)

re: fclean all
