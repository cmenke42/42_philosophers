/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_end_of_simulation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:51:25 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 04:50:44 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool		is_philo_dead(t_program_data *program_data);
static bool		is_end_of_simulation_true(t_program_data *program_data,
					t_philo *philo, bool print_death);
static long int	get_last_meal_time(t_philo *philo);

bool	wait_for_simulation_end(t_program_data *program_data)
{
	while (1)
	{
		if (is_philo_dead(program_data))
			return (true);
		waiting_in_ms(1, 0);
	}
	return (false);
}

static bool	is_philo_dead(t_program_data *program_data)
{
	int			i;

	i = 0;
	while (i < program_data->num_philos)
	{
		if (is_end(&program_data->philos[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	is_end(t_philo *philo)
{
	long int	last_meal;

	if (is_end_of_simulation_true(philo->program_data, philo, false))
		return (true);
	last_meal = get_last_meal_time(philo);
	if (get_time_in_ms() - last_meal > philo->program_data->time_to_die)
	{
		if (is_end_of_simulation_true(philo->program_data, philo, true))
			return (true);
	}
	return (false);
}

static bool	is_end_of_simulation_true(t_program_data *program_data,
			t_philo *philo, bool print_death)
{
	pthread_mutex_lock(&program_data->end_of_simulation_mutex);
	if (program_data->end_of_simulation)
	{
		pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
		return (true);
	}
	if (print_death)
		program_data->end_of_simulation = true;
	pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
	if (print_death)
	{
		print_philo_state(philo, MSG_DIED, true);
		return (true);
	}
	return (false);
}

static long int	get_last_meal_time(t_philo *philo)
{
	long int	last_meal;

	pthread_mutex_lock(&philo->last_meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (last_meal);
}
