/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_end_of_simulation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:51:25 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/16 14:13:40 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_philo_dead(t_program_data *program_data);

bool	is_end_of_simulation(t_program_data *program_data)
{
	while (1)
	{
		if (is_philo_dead(program_data))
			return (true);
		usleep(1000);
	}
	return (false);
}

static bool	is_philo_dead(t_program_data *program_data)
{
	int			i;
	long int	last_meal;

	i = 0;
	while(i < program_data->num_philos)
	{
		pthread_mutex_lock(&program_data->philos[i].last_meal_mutex);
		last_meal = program_data->philos[i].last_meal;
		pthread_mutex_unlock(&program_data->philos[i].last_meal_mutex);
		if (get_time_in_ms() - last_meal> program_data->time_to_die)
		{
			pthread_mutex_lock(&program_data->end_of_simulation_mutex);
			program_data->end_of_simulation = true;
			pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
			print_philo_state(&program_data->philos[i], MSG_DIED);
			return (true);
		}
		i++;
	}
	return (false);
}
