# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/06 19:19:53 by aanzieu           #+#    #+#              #
#*   Updated: 2016/01/12 23:00:53 by aanzieu          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	  ./srcs/ft_strlen.c ./srcs/ft_swap.c

FILESO = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

HEADER_DIR = ./includes/

FLAGS = -Wall -Wextra -Werror -I $(HEADER_DIR) -c

all: $(NAME)

$(NAME) :
	gcc $(FLAGS) $(SRC)
	ar rc $(NAME) $(FILESO)
	ranlib $(NAME)

clean:
	/bin/rm -f $(FILESO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
