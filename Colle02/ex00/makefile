# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/01 17:19:50 by aanzieu           #+#    #+#              #
#    Updated: 2015/11/01 20:45:51 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
FLAGS = -Wall -Wextra -Werror
CLEAN = *.o
SRC = ft_putchar.c ft_putstr.c

all: $(NAME)

$(NAME) :
	gcc -o colle00 colle00.c main.c $(SRC) $(FLAGS)
	gcc -o colle01 colle01.c main.c $(SRC) $(FLAGS)
	gcc -o colle02 colle02.c main.c $(SRC) $(FLAGS)
	gcc -o colle03 colle03.c main.c $(SRC) $(FLAGS)
	gcc -o colle04 colle04.c main.c $(SRC) $(FLAGS)
	gcc -o colle-2 colle-2.c $(SRC) $(FLAGS)

clean:
	rm -f $(CLEAN)

fclean: 
	rm -f $(NAME)

re: fclean all
