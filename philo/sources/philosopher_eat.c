/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:20:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 19:37:28 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	grab_forks(t_philo *philo, pthread_mutex_t *left_fork,
				pthread_mutex_t *right_fork);
static bool	grab_two_forks(t_philo *philo, pthread_mutex_t *left_fork,
				pthread_mutex_t *right_fork);
static void	increment_meal_counter(t_philo *philo);
static bool	put_back_forks(t_philo *philo, pthread_mutex_t *left_fork,
				pthread_mutex_t *right_fork);

bool	philo_eat(t_philo *philo)
{
	long int	last_meal;

	if (!grab_forks(philo, philo->left_fork, philo->right_fork))
		return (false);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time_in_ms();
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	print_philo_state(philo, MSG_EAT, false);
	waiting_in_ms(philo->program_data->time_to_eat, last_meal);
	increment_meal_counter(philo);
	put_back_forks(philo, philo->left_fork, philo->right_fork);
	return (true);
}

static bool	grab_forks(t_philo *philo, pthread_mutex_t *left_fork,
			pthread_mutex_t *right_fork)
{
	if (philo->id % 2)
	{
		if (!grab_two_forks(philo, left_fork, right_fork))
			return (false);
	}
	else if (!grab_two_forks(philo, right_fork, left_fork))
		return (false);
	return (true);
}

static bool	grab_two_forks(t_philo *philo, pthread_mutex_t *fork_1,
			pthread_mutex_t *fork_2)
{
	pthread_mutex_lock(fork_1);
	print_philo_state(philo, MSG_FORK, false);
	if (philo->program_data->num_philos == 1 || is_end(philo))
	{
		pthread_mutex_unlock(fork_1);
		return (false);
	}
	pthread_mutex_lock(fork_2);
	print_philo_state(philo, MSG_FORK, false);
	return (true);
}

static void	increment_meal_counter(t_philo *philo)
{
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->program_data->meals_to_eat)
	{
		pthread_mutex_lock(&philo->program_data->num_philo_full_mutex);
		philo->program_data->num_philo_full++;
		if (philo->program_data->num_philo_full
			== philo->program_data->num_philos)
		{
			pthread_mutex_lock(&philo->program_data->end_of_simulation_mutex);
			philo->program_data->end_of_simulation = true;
			pthread_mutex_unlock(&philo->program_data->end_of_simulation_mutex);
		}
		pthread_mutex_unlock(&philo->program_data->num_philo_full_mutex);
	}
}

static bool	put_back_forks(t_philo *philo, pthread_mutex_t *left_fork,
			pthread_mutex_t *right_fork)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(right_fork);
		pthread_mutex_unlock(left_fork);
		return (true);
	}
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
	return (true);
}
