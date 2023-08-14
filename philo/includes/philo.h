/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:59:08 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/13 22:00:23 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

# include "structs.h"
# include "colors.h"
# include "messages.h"

// validate_and_get_input.c
bool	validate_and_get_input(int argc, char **argv, t_program_data *program_data);

//print_error.c
void	print_error(char *type, char *message);

// create_destory_mutexes.c
bool	create_mutexes(t_program_data *program_data);

// create_destroy_forks.c
bool	create_forks(t_program_data *program_data);
void	destroy_forks(pthread_mutex_t *forks, int num_philos);

// create_philosophers.c
bool	create_philosophers(t_program_data **program_data_reference);

// philosopher_life.c
void	*philosopher_life(void *philo);
void	waiting_in_ms(int time, long int last_meal_time);


//print_philo_state.c
void	print_philo_state(t_philo *philo_data, char *message);

//get_time.c
long int	get_time_in_ms(void);
long int	get_timestamp_in_ms(long int start_time);

#endif