/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:56:49 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 03:37:30 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# include "philo.h"

//philo states
# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIED "died"

//program error types
# define TYPE_ERROR "Error"
# define TYPE_HINT "Hint"
# define ERR_MALLOC "Malloc failed"
# define ERR_MUTEX_INIT "Mutex init failed"
# define ERR_PTHREAD_CREATE "Pthread create failed"
# define ERR_PTHREAD_DETACH "Pthread detach failed"
# define ERR_MUTEX_DESTROY "Mutex destroy failed"

//program error messages
	//input
# define ERR_ARGC "The correct number of arguments is 4 or 5"
# define ERR_POSITIVE_NUM "Numbers must be positive"
# define ERR_ONLY_NUM "Only numbers are allowed"
# define ERR_NUM_TOO_BIG "Number is too large"
# define ERR_NUM_PHILOS "There must be at least 1 philosopher"

//program hints
# define HINT_USAGE "./philo number_of_philosophers time_to_die(ms) \
time_to_eat(ms) time_to_sleep(ms) [number_of_times_each_philosopher_must_eat]"

// print_error.c
void	print_error(char *type, char *message);

//print_philo_state.c
void	print_philo_state(t_philo *philo_data, char *message, bool is_dead);

#endif