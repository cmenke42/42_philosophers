/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:22:09 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/15 22:17:50 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_numbers(t_program_data *program_data)
{
	printf("num_philos:		%d\n", program_data->num_philos);
	printf("time_to_die:		%d\n", program_data->time_to_die);
	printf("time_to_eat:		%d\n", program_data->time_to_eat);
	printf("time_to_sleep:		%d\n", program_data->time_to_sleep);
	printf("num_times_to_eat:	%d\n", program_data->meals_to_eat);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_program_data	*program_data;

	program_data = malloc(sizeof(t_program_data));
	if (!program_data)
		return (print_error(TYPE_ERROR, ERR_MALLOC), 1);
	memset((void *)program_data, 0, sizeof(t_program_data));
	if (!validate_and_get_input(argc, argv, program_data))
		return (1);
	if (program_data->meals_to_eat == 0)
		return (0);
	if (!create_mutexes(program_data))
		return (1);
	program_data->start_time = get_time_in_ms();
	print_philo_numbers(program_data);
	if (!create_philosophers(&program_data))
		return (1);
	return (0);
}
