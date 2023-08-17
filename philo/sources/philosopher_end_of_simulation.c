/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_end_of_simulation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:51:25 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/17 16:50:39 by cmenke           ###   ########.fr       */
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
		usleep(900);
		// waiting_in_ms(1, 0);
	}
	return (false);
}

static bool	is_philo_dead(t_program_data *program_data)
{
	int			i;
	long int	last_meal;

	i = program_data->num_philos - 1;
	while(i >= 0)
	{
		pthread_mutex_lock(&program_data->philos[i].last_meal_mutex);
		last_meal = program_data->philos[i].last_meal;
		pthread_mutex_unlock(&program_data->philos[i].last_meal_mutex);
		if (get_time_in_ms() - last_meal> program_data->time_to_die)
		{
			pthread_mutex_lock(&program_data->end_of_simulation_mutex);
			{
				if (program_data->end_of_simulation)
				{
					pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
					return (true);
				}
				program_data->end_of_simulation = true;
			}
			pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
			print_philo_state(&program_data->philos[i], MSG_DIED, true);
			return (true);
		}
		i--;
	}
	return (false);
}
