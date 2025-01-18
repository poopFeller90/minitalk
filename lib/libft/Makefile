CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

NAME = libft.a
SRC = ft_atoi.c ft_strncmp.c
#OBJ = ft_putchar.o ft_atoi.o
OBJ = $(SRC:.c=.o)
HEADER = libft.h

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
