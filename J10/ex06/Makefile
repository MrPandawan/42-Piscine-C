# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#   Makefile                                            :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#   by: aanzieu <marvin@42.fr>                     +#+  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#   created: 2016/01/01 19:33:49 by aanzieu           #+#    #+#               #
#*   Updated: 2016/01/17 11:34:13 by aanzieu          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = do-op

FLAGS = -Wall -Wextra -Werror

O = -o $(NAME)

SRC = ft_atoi.c ft_write.c ft_do_op.c main.c

HEADER = header.h

OBJ =

all = $(NAME)

$(NAME) :
	gcc $(FLAGS) $(SRC) $(O)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
