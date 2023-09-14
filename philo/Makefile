# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 21:26:40 by cmenke            #+#    #+#              #
#    Updated: 2023/08/21 17:40:42 by cmenke           ###   ########.fr        #
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
		time.c \
		philosopher_eat.c \
		philosopher_end_of_simulation.c

OBJS := $(patsubst %.c, ${OBJDIR}/%.o, ${SRCS})

HEADER := $(addprefix includes/,philo.h \
								messages.h \
								structs.h \
								colors.h)

#Production flags
CFLAGS := -Wall -Werror -Wextra -I includes
LDFLAGS := -pthread
#Development flags
# CFLAGS += -g -O0
# CFLAGS += -fsanitize=thread
# CFLAGS += -fsanitize=address

CC := cc

RM := rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME}

${OBJDIR}/%.o: ${SRCDIR}/%.c ${HEADER} | ${OBJDIR}
	${CC} ${CFLAGS} ${LDFLAGS} -c $< -o $@

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	${RM} -r ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: