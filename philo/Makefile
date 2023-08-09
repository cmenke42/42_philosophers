# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 21:26:40 by cmenke            #+#    #+#              #
#    Updated: 2023/08/09 20:42:48 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRCDIR := sources

SRCS := $(addprefix ${SRCDIR}/,main.c \
								ft_isdigit.c \
								ft_putstr_fd.c \
								ft_putnbr_fd.c \
								input_validation.c \
								print_message.c)

OBJS := ${SRCS:.c=.o}

HEADER := includes/philo.h

#Production flags
#CFLAGS := -Wall -Werror -Wextra -I includes

#Development flags
CFLAGS := -Wall -Wextra -I includes -g -O0 #-fsanitize=address

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