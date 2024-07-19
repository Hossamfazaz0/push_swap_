Name = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard algo/*.c) $(wildcard moves/*.c) $(wildcard parsing/*.c) $(wildcard *.c)

OBJ = $(SRCS:.c=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

.PHONY: all clean fclean
