/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:37:55 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 17:40:08 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_philo_data(t_program_data *program_data);

void	print_data_of_one_philo(t_one_philo *philo)
{
	printf(YELLOW"id:			%d\n" DEFAULT, philo->id);
	printf("time_of_last_meal:	%ld\n", philo->time_of_last_meal);
	printf("meals_left:		%d\n", philo->meals_left);
	printf("time_to_die:		%d\n", philo->program_data.time_to_die);
	printf("time_to_eat:		%d\n", philo->program_data.time_to_eat);
	printf("time_to_sleep:		%d\n", philo->program_data.time_to_sleep);
	// printf("address of program_data:	%p\n", &philo->program_data);
	// printf("\n");
}


bool	create_philos(t_program_data *program_data)
{
	int			i;
	pthread_t	philo_thread;

	if (!create_philo_data(program_data))
		return (false);
	i = 0;
	while (i < program_data->num_philos)
	{
		if (pthread_create(&philo_thread, NULL, \
			&philo_life, (void *)program_data->philos[i]))
			return (ft_putstr_fd("Error creating philo thread", STDERR_FILENO), false);
		pthread_detach(philo_thread);
		i++;
	}
	return (true);
}

bool	create_philo_data(t_program_data *program_data)
{
	int	i;

	program_data->philos = malloc(sizeof(t_one_philo *) * program_data->num_philos);
	memset((void *)program_data->philos, 0, \
		sizeof(t_one_philo *) * program_data->num_philos);
	if (!program_data->philos)
		return (ft_putstr_fd("Error creating philos", STDERR_FILENO), false);
	i = 0;
	while (i < program_data->num_philos)
	{
		program_data->philos[i] = malloc(sizeof(t_one_philo));
		if (!program_data->philos[i])
			return (free_philos(program_data), ft_putstr_fd("Error creating philos", STDERR_FILENO), false); // free the rest
		program_data->philos[i]->id = i + 1;
		program_data->philos[i]->program_data = *program_data;
		program_data->philos[i]->meals_left = \
			program_data->num_times_to_eat;
		program_data->philos[i]->time_of_last_meal = \
			program_data->start_of_simulation;
		// print_data_of_one_philo(program_data->philos[i]);
		i++;
	}
	return (true);
}

void	free_philos(t_program_data *program_data)
{
	int	i;

	i = 0;
	while (i < program_data->num_philos)
	{
		if (program_data->philos[i])
			free(program_data->philos[i]);
		i++;
	}
	if (program_data->philos)
		free(program_data->philos);
}