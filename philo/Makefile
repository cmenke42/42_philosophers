# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 21:26:40 by cmenke            #+#    #+#              #
#    Updated: 2023/08/14 18:17:14 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRCDIR := sources

OBJDIR := objects

SRCS := main.c \
		print_error.c \
		validate_and_get_input.c \
		create_destroy_forks.c \
		create_destroy_philosophers.c \
		create_destroy_mutexes.c \
		philosopher_life.c \
		print_philo_state.c \
		get_time.c

OBJS := $(patsubst %.c, ${OBJDIR}/%.o, ${SRCS})

HEADER := $(addprefix includes/,philo.h \
								messages.h \
								structs.h \
								colors.h)

#Production flags
#CFLAGS := -Wall -Werror -Wextra -I includes

#Development flags
CFLAGS := -Wall -Wextra -I includes -g -O0 -fsanitize=thread #-fsanitize=address 

CC := cc

RM := rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJDIR}/%.o: ${SRCDIR}/%.c ${HEADER} | ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	${RM} -r ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: