/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:22:09 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 02:57:26 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_philosopher_threads_to_finish(t_program_data *program_data, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(program_data->philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program_data	*program_data;

	program_data = malloc(sizeof(t_program_data));
	if (!program_data)
		return (print_error(TYPE_ERROR, ERR_MALLOC), 1);
	memset((void *)program_data, 0, sizeof(t_program_data));

	if (!validate_and_get_input(argc, argv, program_data)) //make a clean function
		return (free(program_data), 1);
	// if (program_data->num_philos == 1) //make an extra thread for 1 philo
	// {
	// 	printf("0 1 has taken a fork\n");
	// 	waiting_in_ms(program_data->time_to_die, 0);
	// 	printf("%d 1 died\n", program_data->time_to_die);
	// 	return (0);
	// }
	if (program_data->meals_to_eat == 0 && program_data->num_philos > 1) //make a clean function
		return (free(program_data), 0);
	if (!create_mutexes(program_data)) //make a clean function
		return (free(program_data), 1);
	// print_philo_numbers(program_data);
	if (!start_simulation(&program_data))//make a clean function
		return (false);
	// waiting_in_ms(program_data->time_to_die * 0.9, 0);
	else
		is_end_of_simulation(program_data);
	
	wait_for_philosopher_threads_to_finish(program_data, program_data->num_philos);
	destroy_mutexes(program_data);
	destroy_philosophers(program_data);
	free(program_data);
	//free memory and destroy mutexes
	//clear up and wait for all to finish
	return (0);
}
