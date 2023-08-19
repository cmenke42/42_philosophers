/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:08:30 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 03:44:11 by cmenke           ###   ########.fr       */
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
	while (!is_end(philo_data))
	{
		if (!philo_eat(philo_data))
			return (NULL);
		if (is_end(philo_data))
			return (NULL);
		philo_sleep(philo_data);
		if (is_end(philo_data))
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
	long int	start_time;

	if (last_meal_time == 0)
		start_time = get_time_in_ms();
	else
		start_time = last_meal_time;
	while (get_time_in_ms() - start_time < time)
		usleep(1000);
}

bool	is_end(t_philo *philo)
{
	long int	last_meal;

	pthread_mutex_lock(&philo->program_data->end_of_simulation_mutex);
	if (philo->program_data->end_of_simulation)
		return (pthread_mutex_unlock(
				&philo->program_data->end_of_simulation_mutex), true);
	pthread_mutex_unlock(&philo->program_data->end_of_simulation_mutex);
	pthread_mutex_lock(&philo->last_meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (get_time_in_ms() - last_meal > philo->program_data->time_to_die)
	{
		pthread_mutex_lock(&philo->program_data->end_of_simulation_mutex);
		if (philo->program_data->end_of_simulation)
		{
			pthread_mutex_unlock(&philo->program_data->end_of_simulation_mutex);
			return (true);
		}
		philo->program_data->end_of_simulation = true;
		pthread_mutex_unlock(&philo->program_data->end_of_simulation_mutex);
		print_philo_state(philo, MSG_DIED, true);
		return (true);
	}
	return (false);
}
