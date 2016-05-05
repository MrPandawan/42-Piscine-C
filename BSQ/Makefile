NAME = bsq

CC = gcc

FLAG = -c -Wall -Werror -Wextra

SRC = ft_bsq.c ft_buff.c ft_checkbsq.c ft_free.c ft_nbr.c ft_print.c \
	  ft_resolve.c

OBJ = ft_bsq.o ft_buff.o ft_checkbsq.o ft_free.o ft_nbr.o ft_print.o \
	  ft_resolve.o

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
