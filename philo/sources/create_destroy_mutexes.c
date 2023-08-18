/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy_mutexes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:03:52 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/18 15:55:13 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_mutexes(t_program_data *program_data)
{
	if (!create_forks(program_data))
		return (false);
	if (pthread_mutex_init(&(program_data->end_of_simulation_mutex), NULL))
	{
		print_error(ERR_MUTEX_INIT, "end_of_simulation_mutex");
		destroy_forks(program_data->forks, program_data->num_philos);
		return (false);
	}
	if (pthread_mutex_init(&(program_data->num_philo_finished_eating_mutex), NULL))
	{
		print_error(ERR_MUTEX_INIT, "num_philo_finished_eating_mutex");
		destroy_forks(program_data->forks, program_data->num_philos);
		pthread_mutex_destroy(&(program_data->end_of_simulation_mutex));
		return (false);
	}
	if (pthread_mutex_init(&(program_data->start_simulation_mutex), NULL))
	{
		print_error(ERR_MUTEX_INIT, "num_philo_finished_eating_mutex");
		destroy_forks(program_data->forks, program_data->num_philos);
		pthread_mutex_destroy(&(program_data->end_of_simulation_mutex));
		pthread_mutex_destroy(&(program_data->num_philo_finished_eating_mutex));
		return (false);
	}
	return (true);
}

void	destroy_mutexes(t_program_data *program_data)
{
	destroy_forks(program_data->forks, program_data->num_philos);
	pthread_mutex_destroy(&(program_data->end_of_simulation_mutex));
	pthread_mutex_destroy(&(program_data->num_philo_finished_eating_mutex));
	pthread_mutex_destroy(&(program_data->start_simulation_mutex));
}
