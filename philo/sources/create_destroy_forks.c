/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:48:54 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/13 20:55:54 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_forks(t_program_data *program_data)
{
	int	i;

	i = 0;
	program_data->forks = malloc(sizeof(pthread_mutex_t) * program_data->num_philos);
	if (!program_data->forks)
		return (print_error(ERR_MALLOC, "creating forks"), false);
	memset((void *)program_data->forks, 0, sizeof(pthread_mutex_t) * program_data->num_philos);
	while (i < program_data->num_philos)
	{
		if (pthread_mutex_init(&(program_data->forks[i]), NULL))
		{
			print_error(ERR_MUTEX_INIT, "forks");
			destroy_forks(program_data->forks, i);
			return (false);
		}
		i++;
	}
	return (true);
}

void	destroy_forks(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&(forks[i])))
			print_error(ERR_MUTEX_DESTROY, "forks");
		i++;
	}
	if (forks)
		free(forks);
}
