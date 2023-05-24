# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 09:40:43 by kmouradi          #+#    #+#              #
#    Updated: 2022/12/03 18:03:01 by kmouradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CL=ar -rc
CN=rm -rf
FLAGS=-Wall -Wextra -Werror
SRC= ft_putchar ft_putstr ft_putnbr ft_puthexa ft_putnbr_unsigned ft_putadrs ft_printf

OBJ=${SRC:=.o}

NAME=libftprintf.a

all:${NAME}

${NAME}:${OBJ}
	${CL} ${NAME} ${OBJ}

%.o: %.c  ft_printf.h
	${CC} ${FLAGS} -c $<

clean:
	${CN} ${OBJ}

fclean: clean
	${CN} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re