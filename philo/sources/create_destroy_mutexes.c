/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy_mutexes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:03:52 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 05:01:53 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_mutexes(t_program_data *program_data)
{
	if (pthread_mutex_init(&(program_data->end_of_simulation_mutex), NULL))
		return (print_error(ERR_MUTEX_INIT, "end_of_simulation_mutex"), false);
	if (pthread_mutex_init(&(program_data->num_philo_full_mutex), NULL))
	{
		pthread_mutex_destroy(&(program_data->end_of_simulation_mutex));
		return (print_error(ERR_MUTEX_INIT, "num_philo_full_mutex"), false);
	}
	if (pthread_mutex_init(&(program_data->start_simulation_mutex), NULL))
	{
		pthread_mutex_destroy(&(program_data->end_of_simulation_mutex));
		pthread_mutex_destroy(&(program_data->num_philo_full_mutex));
		return (print_error(ERR_MUTEX_INIT, "start_simulation_mutex"), false);
	}
	if (!create_forks(program_data))
		return (destroy_mutexes(program_data), false);
	return (true);
}

void	destroy_mutexes(t_program_data *program_data)
{
	destroy_forks(program_data, program_data->num_philos);
	pthread_mutex_destroy(&(program_data->end_of_simulation_mutex));
	pthread_mutex_destroy(&(program_data->num_philo_full_mutex));
	pthread_mutex_destroy(&(program_data->start_simulation_mutex));
}
