/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:22:09 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 03:53:44 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program_data	*program_data;

	program_data = malloc(sizeof(t_program_data));
	if (!program_data)
		return (print_error(TYPE_ERROR, ERR_MALLOC), 1);
	memset((void *)program_data, 0, sizeof(t_program_data));
	if (!validate_and_get_input(argc, argv, program_data))
		return (free(program_data), 1);
	if (program_data->meals_to_eat == 0)
		return (free(program_data), 0);
	if (!create_mutexes(program_data))
		return (free(program_data), 1);
	if (!start_simulation(&program_data))
		return (free(program_data), 1);
	is_end_of_simulation(program_data);
	wait_for_philosophers(program_data, program_data->num_philos);
	destroy_mutexes(program_data);
	destroy_philosophers(program_data, program_data->num_philos);
	free(program_data);
	return (0);
}

void	wait_for_philosophers(t_program_data *program_data, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(program_data->philos[i].thread, NULL);
		i++;
	}
}
