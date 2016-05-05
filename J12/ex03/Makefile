NAME = ft_hexdump

CC = gcc

FLAG = -c -Wall -Werror -Wextra

SRC = hexdumpcopy.c ft_print.c ft_sdup.c ft_option.c ft_hexa_print.c

OBJ = hexdumpcopy.o ft_print.o ft_sdup.o ft_option.o ft_hexa_print.o

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
