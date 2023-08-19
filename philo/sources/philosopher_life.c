/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:08:30 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 04:40:20 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_philo *philo);
static void	wait_for_simulation_start(pthread_mutex_t *start_simulation_mutex);

void	*philosopher_life(void *data_of_philo)
{
	t_philo	*philo;

	philo = (t_philo *)data_of_philo;
	wait_for_simulation_start(&philo->program_data->start_simulation_mutex);
	if (philo->id % 2 == 0)
		waiting_in_ms(philo->program_data->time_to_eat / 2, 0);
	while (!is_end(philo))
	{
		if (!philo_eat(philo))
			return (NULL);
		if (is_end(philo))
			return (NULL);
		philo_sleep(philo);
		if (is_end(philo))
			return (NULL);
		print_philo_state(philo, MSG_THINK, false);
	}
	return (NULL);
}

static void	philo_sleep(t_philo *philo)
{
	print_philo_state(philo, MSG_SLEEP, false);
	waiting_in_ms(philo->program_data->time_to_sleep, 0);
}

static void	wait_for_simulation_start(pthread_mutex_t *start_simulation_mutex)
{
	pthread_mutex_lock(start_simulation_mutex);
	pthread_mutex_unlock(start_simulation_mutex);
}
