# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 21:26:40 by cmenke            #+#    #+#              #
#    Updated: 2023/08/08 21:31:11 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRCDIR := sources

SRCS := $(addprefix ${SRCDIR}/,main.c)

OBJS := ${SRCS:.c=.o}

HEADER := includes/philo.h

#Production flags
#CFLAGS := -Wall -Werror -Wextra

#Development flags
CFLAGS := -Wall -Werror -Wextra -g -O0 #-fsanitize=address

CC := cc

RM := rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJS}: ${HEADER}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: