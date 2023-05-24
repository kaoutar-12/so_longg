# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 16:43:36 by kmouradi          #+#    #+#              #
#    Updated: 2023/05/21 17:47:42 by kmouradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CN=rm -rf
FLAGS= -Wall -Wextra -Werror
LINKS= -lmlx -framework OpenGL -framework AppKit
SOURCE= map_close.c check_name.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c\
read_map.c so_long.c get_next_line.c ft_playable.c ft_strchr.c \
map_size.c  ft_game.c ft_moves.c ft_close_game.c valid_path.c
OBJECT=${SOURCE:.c=.o}

NAME=so_long

all: ftprintf ${NAME}

${NAME}:${OBJECT}
	${CC} ${FLAGS} ${OBJECT} ${LINKS} printf/libftprintf.a -o ${NAME}

%.o: %.c  so_long.h
	${CC} ${FLAGS} -c $<

clean:
	cd printf && make clean
	${CN} ${OBJECT}

fclean: clean
	cd printf && make fclean
	${CN} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

ftprintf :
	cd printf && make
