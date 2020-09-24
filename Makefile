# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: peerdb <peerdb@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/24 12:54:54 by peerdb        #+#    #+#                  #
#    Updated: 2020/09/24 13:02:18 by peerdb        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

ifeq ($(shell uname), Linux)
 CC = gcc
else
 CC = clang
endif
FLAGS = -Wall -Wextra -Werror -ansi -O3 -pedantic -std=c99

FILES = get_next_line.c get_next_line_utils.c
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(FILES) $(FLAGS) -I .
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
