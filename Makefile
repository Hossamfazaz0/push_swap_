# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 19:49:19 by hfazaz            #+#    #+#              #
#    Updated: 2024/07/27 14:30:16 by hfazaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = algo/algo_utils.c algo/buble_sort.c algo/sort_five.c \
	algo/sort_three.c algo/sort_four.c algo/sort.c \
	moves/push.c moves/rotate_reverse.c moves/rotate.c \
	moves/swap.c parsing/check.c parsing/chosing_algo.c \
	main.c utils_libft.c utils.c

OBJ = $(SRCS:.c=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re : fclean all

.PHONY: all clean fclean
