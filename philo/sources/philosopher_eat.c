/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:20:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/16 17:41:01 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	grab_two_forks(t_philo *philo, pthread_mutex_t *left_fork, pthread_mutex_t *right_fork);
bool	put_back_two_forks(t_philo *philo, pthread_mutex_t *left_fork, pthread_mutex_t *right_fork);


bool	philo_eat(t_philo *philo)
{
	long int	last_meal;

	// pthread_mutex_lock(&philo->last_meal_mutex);
	// last_meal = philo->last_meal;
	// if (get_time_in_ms() - last_meal> philo->program_data->time_to_die)
	// {
	// 	pthread_mutex_lock(&philo->program_data->end_of_simulation_mutex);
	// 	philo->program_data->end_of_simulation = true;
	// 	pthread_mutex_unlock(&philo->program_data->end_of_simulation_mutex);
	// 	pthread_mutex_unlock(&philo->last_meal_mutex);
	// 	print_philo_state(philo, MSG_DIED, true);
	// 	return (false);
	// }
	// pthread_mutex_unlock(&philo->last_meal_mutex);
	grab_two_forks(philo, philo->left_fork, philo->right_fork);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time_in_ms();
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	print_philo_state(philo, MSG_EAT, false);
	waiting_in_ms(philo->program_data->time_to_eat, last_meal);
	put_back_two_forks(philo, philo->left_fork, philo->right_fork);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->program_data->meals_to_eat)
	{
		pthread_mutex_lock(&philo->program_data->num_philo_finished_eating_mutex);
		philo->program_data->num_philo_finished_eating++;
		if (philo->program_data->num_philo_finished_eating == philo->program_data->num_philos)
		{
			pthread_mutex_lock(&philo->program_data->end_of_simulation_mutex);
			philo->program_data->end_of_simulation = true;
			pthread_mutex_unlock(&philo->program_data->end_of_simulation_mutex);
		}
		pthread_mutex_unlock(&philo->program_data->num_philo_finished_eating_mutex);
	}
	return (true);
}

bool	grab_two_forks(t_philo *philo, pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	if(philo->id % 2)
	{
		pthread_mutex_lock(left_fork);
		print_philo_state(philo, MSG_FORK, false);
		pthread_mutex_lock(right_fork); //error ?
		print_philo_state(philo, MSG_FORK, false);
	}
	else
	{
		pthread_mutex_lock(right_fork); //error ?
		print_philo_state(philo, MSG_FORK, false);
		pthread_mutex_lock(left_fork);
		print_philo_state(philo, MSG_FORK, false);
	}
	return (true);
}

bool	put_back_two_forks(t_philo *philo, pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	if(philo->id % 2)
	{
		pthread_mutex_unlock(left_fork);
		pthread_mutex_unlock(right_fork); //error ?
	}
	else
	{
		pthread_mutex_unlock(right_fork); //error ?
		pthread_mutex_unlock(left_fork);
	}
	return (true);
}
