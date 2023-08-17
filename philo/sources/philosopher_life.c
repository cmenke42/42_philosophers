/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:08:30 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/17 16:46:46 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_philo *philo_data);

void	*philosopher_life(void *philo)
{
	t_philo	*philo_data;

	philo_data = (t_philo *)philo;
	pthread_mutex_lock(&philo_data->program_data->start_simulation_mutex);
	pthread_mutex_unlock(&philo_data->program_data->start_simulation_mutex);
	if (philo_data->id % 2 == 0)
		waiting_in_ms(philo_data->program_data->time_to_eat / 2, 0);
	// print_philo_state(philo_data, "hello", false);
	while (1) //mutex!
	{
		if (is_end(philo_data->program_data))
			return (NULL);
		philo_eat(philo_data);
		if (is_end(philo_data->program_data))
			return (NULL);
		philo_sleep(philo_data);
		if (is_end(philo_data->program_data))
			return (NULL);
		print_philo_state(philo_data, MSG_THINK, false);
	}
	return (NULL);
}

static void	philo_sleep(t_philo *philo_data)
{
	print_philo_state(philo_data, MSG_SLEEP, false);
	waiting_in_ms(philo_data->program_data->time_to_sleep, 0);
}

//to reduce the delay of usleep
void	waiting_in_ms(int time, long int last_meal_time)
{
	long int start_time;

	if (last_meal_time == 0)
		start_time = get_time_in_ms();
	else
		start_time = last_meal_time;
	while (get_time_in_ms() - start_time < time)
		usleep(1000);
}

bool	is_end(t_program_data *program_data)
{
	pthread_mutex_lock(&program_data->end_of_simulation_mutex);
	if (program_data->end_of_simulation)
	{
		pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
		return (true);
	}
	pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
	return (false);
}
