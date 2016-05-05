# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/14 18:09:02 by aanzieu           #+#    #+#              #
#    Updated: 2016/02/14 21:19:14 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

CC = gcc

FLAG = -c -Wall -Werror -Wextra

SRC = tail.c

OBJ = tail.o

HDR = header.h

RM = rm -f

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) $(SRC) $(HDR)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
