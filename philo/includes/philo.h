/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:59:08 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 04:28:34 by cmenke           ###   ########.fr       */
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

// main.c
void		wait_for_philosophers(t_program_data *program_data,
				int num_philos);

// validate_and_get_input.c
bool		validate_and_get_input(int argc, char **argv,
				t_program_data *program_data);

//print_error.c
void		print_error(char *type, char *message);

// create_destory_mutexes.c
bool		create_mutexes(t_program_data *program_data);
void		destroy_mutexes(t_program_data *program_data);

// create_destroy_forks.c
bool		create_forks(t_program_data *program_data);
void		destroy_forks(t_program_data *program_data, int num_philos);

// prepare_philosopher_data.c
bool		start_simulation(t_program_data **program_data_reference);
void		destroy_philosophers(t_program_data *program_data, int num_philos);

// philosopher_life.c
void		*philosopher_life(void *data_of_philo);
bool		is_end(t_philo *philo);

//time.c
void		waiting_in_ms(int time, long int last_meal_time);
long int	get_timestamp_in_ms(long int start_time);
long int	get_time_in_ms(void);

// philo_eat.c
bool		philo_eat(t_philo *philo);

//philosopher_end_of_simulation.c
bool		wait_for_simulation_end(t_program_data *program_data);

#endif