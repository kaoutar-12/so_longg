# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 16:43:36 by kmouradi          #+#    #+#              #
#    Updated: 2023/05/16 13:21:27 by kmouradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CN=rm -rf
FLAGS= -Wall -Wextra -Werror
LINKS= 
SOURCE= check_map.c check_name.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c\
read_map.c so_long.c get_next_line.c ft_playable.c ft_strchr.c
OBJECT=${SOURCE:.c=.o}

NAME=so_long

all:${NAME}

${NAME}:${OBJECT}
	${CC} ${OBJECT} ${OBJECT} -o ${NAME}

%.o: %.c  so_long.h
	${CC} ${FLAGS} -c $<

clean:
	${CN} ${OBJECT}

fclean: clean
	${CN} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
