/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:25:10 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 21:23:55 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_one_philo *philo);
static void	philo_sleep(t_one_philo *philo_data);
static bool	is_end_of_simulation(t_one_philo *philo_data);

// timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died

void	*philo_life(void *philo)
{
	t_one_philo *philo_data;

	philo_data = (t_one_philo *)philo;
	while (!is_end_of_simulation(philo_data))
	{
		philo_eat(philo_data);
		philo_sleep(philo_data);
		print_message(philo_data, "is thinking");
	}
	return (NULL);
}

static void	philo_eat(t_one_philo *philo_data)
{
	long int	time_of_last_meal;
	//mutex for fork getting
		//get two forks
	//End of mutex for fork getting
	pthread_mutex_lock(&(philo_data->program_data.time_of_last_meal_mutex));
	philo_data->time_of_last_meal = get_time_in_ms();
	time_of_last_meal = philo_data->time_of_last_meal;
	pthread_mutex_unlock(&(philo_data->program_data.time_of_last_meal_mutex));
	print_message(philo_data, "is eating");
	waiting_in_ms(philo_data->program_data.time_to_eat, time_of_last_meal);
}

static void	philo_sleep(t_one_philo *philo_data)
{
	print_message(philo_data, "is sleeping");
	waiting_in_ms(philo_data->program_data.time_to_sleep, 0);
}

static bool	is_end_of_simulation(t_one_philo *philo_data)
{
	pthread_mutex_lock(&(philo_data->program_data.end_of_simulation_mutex));
	if (philo_data->program_data.end_of_simulation)
	{
		pthread_mutex_unlock(&(philo_data->program_data.end_of_simulation_mutex));
		return (true);
	}
	pthread_mutex_unlock(&(philo_data->program_data.end_of_simulation_mutex));
	return (false);
}