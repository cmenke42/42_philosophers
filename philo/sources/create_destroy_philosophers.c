/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:59:30 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/13 21:07:51 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_philosophers(t_program_data **program_data_reference)
{
	int			i;
	t_program_data	*program_data;

	i = 0;
	program_data = *program_data_reference;
	program_data->philos = malloc(sizeof(t_philo) * program_data->num_philos);
	if (!program_data->philos)
		return (print_error(ERR_MALLOC, "creating philos"), false);
	memset((void *)program_data->philos, 0, sizeof(t_philo) * program_data->num_philos);
	while (i < program_data->num_philos)
	{
		program_data->philos[i].program_data = *program_data_reference;
		program_data->philos[i].id = i;
		program_data->philos[i].last_meal = program_data->start_time;
		program_data->philos[i].left_fork = &(program_data->forks[i]);
		program_data->philos[i].right_fork = &(program_data->forks[(i + 1) % program_data->num_philos]);
		pthread_mutex_init(&(program_data->philos[i].last_meal_mutex), NULL);// TODO: error check
		if (pthread_create(&program_data->philos[i].thread, NULL, &philosopher_life, (void *)&(program_data->philos[i])))
		{
			print_error(ERR_PTHREAD_CREATE, "philosopher"); //cleanup?
			return (false);
		}
		pthread_detach(program_data->philos[i].thread);
		i++;
	}
	return (true);
}
