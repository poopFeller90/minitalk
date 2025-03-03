CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC = include/

HED = include/minitalk.h
HEDB = include/minitalk_bonus.h

HEDT = tools/tools.h

SRC1 = src/server.c
SRC2 = src/client.c

OBJ1 = src/server.o
OBJ2 = src/client.o

BSRC1 = src/server_bonus.c
BSRC2 = src/client_bonus.c
BSRC3 = src/tools.c

BOBJ1 = src/server_bonus.o
BOBJ2 = src/client_bonus.o
BOBJ3 = src/tools.c

TSRC = tools/ft_atoi.c \
tools/ft_strncmp.c \
tools/ft_countd.c \
tools/ft_handle_specifier.c \
tools/ft_printf.c \
tools/ft_printhex.c \
tools/ft_printmemory.c \
tools/ft_putchari.c \
tools/ft_putnbri.c \
tools/ft_putstri.c \
tools/ft_putunbri.c \
tools/ft_strleni.c \
tools/ft_switch.c

TOBJ = tools/ft_atoi.o \
tools/ft_strncmp.o \
tools/ft_countd.o \
tools/ft_handle_specifier.o \
tools/ft_printf.o \
tools/ft_printhex.o \
tools/ft_printmemory.o \
tools/ft_putchari.o \
tools/ft_putnbri.o \
tools/ft_putstri.o \
tools/ft_putunbri.o \
tools/ft_strleni.o \
tools/ft_switch.o

SRV = server
CLT = client

BSRV = server_bonus
BCLT = client_bonus

all: $(SRV) $(CLT)

bonus: $(BSRV) $(BCLT)

$(SRV): $(OBJ1) $(TOBJ)
	$(CC) $(CFLAGS) -I$(INC) $(OBJ1) $(TOBJ) -o $(SRV)

$(CLT): $(OBJ2) $(TOBJ)
	$(CC) $(CFLAGS) -I$(INC) $(OBJ2) $(TOBJ) -o $(CLT)

$(BSRV): $(BOBJ1) $(BOBJ3) $(TOBJ)
	$(CC) $(CFLAGS) -I$(INC) $(BOBJ1) $(BOBJ3) $(TOBJ) -o $(BSRV)

$(BCLT): $(BOBJ2) $(TOBJ)
	$(CC) $(CFLAGS) -I$(INC) $(BOBJ2) $(TOBJ) -o $(BCLT)

ft_%.o: ft_%.c $(HEDT)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HED)
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEDB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ1) $(OBJ2) $(BOBJ1) $(BOBJ2) $(TOBJ)

fclean: clean
	$(RM) $(SRV) $(CLT) $(BSRV) $(BCLT)

re: fclean all

.PHONY: all clean fclean re
