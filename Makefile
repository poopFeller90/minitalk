CC = cc
CFLAGS = -Wall -Wextra -Werror -no-pie
RM = rm -rf

HED = include/minitalk.h

LIBFT = lib/libft/libft.a
FTPRN = lib/libftprintf/libftprintf.a

SRC1 = src/server.c
SRC2 = src/client.c

BSRC1 = src/server_bonus.c
BSRC2 = src/client_bonus.c

SRV = server
CLT = client

BSRV = server_bonus
BCLT = client_bonus

all: $(SRV) $(CLT)

bonus: $(BSRV) $(BCLT)

$(SRV): $(LIBFT) $(FTPRN) $(HED) $(SRC1)
	$(CC) $(CFLAGS) $(SRC1) $(LIBFT) $(FTPRN) -o $(SRV)

$(CLT): $(LIBFT) $(FTPRN) $(HED) $(SRC2)
	$(CC) $(CFLAGS) $(SRC2) $(LIBFT) $(FTPRN) -o $(CLT)

$(BSRV): $(LIBFT) $(FTPRN) $(HED) $(BSRC1)
	$(CC) $(CFLAGS) $(BSRC1) $(LIBFT) $(FTPRN) -o $(BSRV)

$(BCLT): $(LIBFT) $(FTPRN) $(HED) $(BSCR2)
	$(CC) $(CLFAGS) $(BSRC2) $(LIBFT) $(FTPRN) -o $(BCLT)

$(LIBFT):
	make -C lib/libft/

$(FTPRN):
	make -C lib/libftprintf/

clean:
	$(RM) $(LIBFT) $(FTPRN) lib/libft/*.o lib/libftprintf/*.o

fclean: clean
	$(RM) $(SRV) $(CLT) $(BSRV) $(BCLT)

re: fclean all

.PHONY: all fclean clean re
