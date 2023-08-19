/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy_philosophers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:05:14 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 03:40:41 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	prepare_philosopher_data(t_program_data **program_data_reference);
static bool	launch_philosopher_threads(t_program_data **program_data_reference);
static void	set_last_meal_to_start_time(t_program_data *program_data);

bool	start_simulation(t_program_data **program_data_reference)
{
	if (!prepare_philosopher_data(program_data_reference))
		return (false);
	pthread_mutex_lock(&(*program_data_reference)->start_simulation_mutex);
	if (!launch_philosopher_threads(program_data_reference))
		return (false);
	(*program_data_reference)->start_time = get_time_in_ms();
	set_last_meal_to_start_time(*program_data_reference);
	pthread_mutex_unlock(&(*program_data_reference)->start_simulation_mutex);
	return (true);
}

static bool	prepare_philosopher_data(t_program_data **program_data_reference)
{
	int				i;
	t_program_data	*program_data;

	i = 0;
	program_data = *program_data_reference;
	program_data->philos = malloc(sizeof(t_philo) * program_data->num_philos);
	if (!program_data->philos)
		return (print_error(ERR_MALLOC, "creating philos"), false);
	memset((void *)program_data->philos, 0,
		sizeof(t_philo) * program_data->num_philos);
	while (i < program_data->num_philos)
	{
		program_data->philos[i].program_data = *program_data_reference;
		program_data->philos[i].id = i;
		program_data->philos[i].left_fork = &(program_data->forks[i]);
		program_data->philos[i].right_fork = 
			&(program_data->forks[(i + 1) % program_data->num_philos]);
		if (pthread_mutex_init(&(program_data->philos[i].last_meal_mutex),
				NULL))
			return (print_error(ERR_MUTEX_INIT, "last_meal_mutex"),
				destroy_philosophers(program_data, i), false);
		i++;
	}
	return (true);
}

static bool	launch_philosopher_threads(t_program_data **program_data_reference)
{
	int				i;
	t_program_data	*program_data;

	i = 0;
	program_data = *program_data_reference;
	while (i < program_data->num_philos)
	{
		if (pthread_create(&program_data->philos[i].thread,
				NULL, &philosopher_life, (void *)&(program_data->philos[i])))
		{
			print_error(ERR_PTHREAD_CREATE, "philosopher");
			pthread_mutex_lock(&program_data->end_of_simulation_mutex);
			program_data->end_of_simulation = true;
			pthread_mutex_unlock(&program_data->end_of_simulation_mutex);
			pthread_mutex_unlock(&program_data->start_simulation_mutex);
			wait_for_philosophers(program_data, i);
			destroy_philosophers(program_data, i);
			destroy_mutexes(program_data);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	set_last_meal_to_start_time(t_program_data *program_data)
{
	int	i;

	i = 0;
	while (i < program_data->num_philos)
	{
		pthread_mutex_lock(&(program_data->philos[i].last_meal_mutex));
		program_data->philos[i].last_meal = program_data->start_time;
		pthread_mutex_unlock(&(program_data->philos[i].last_meal_mutex));
		i++;
	}
}

void	destroy_philosophers(t_program_data *program_data, int num_philos)
{
	int	i;

	i = 0;
	if (!program_data->philos)
		return ;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&(program_data->philos[i].last_meal_mutex));
		i++;
	}
	free(program_data->philos);
	program_data->philos = NULL;
}
