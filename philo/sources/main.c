/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:56:15 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 15:06:28 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_numbers(t_program_data *program_data)
{
	printf("num_philos:		%d\n", program_data->num_philos);
	printf("time_to_die:		%d\n", program_data->time_to_die);
	printf("time_to_eat:		%d\n", program_data->time_to_eat);
	printf("time_to_sleep:		%d\n", program_data->time_to_sleep);
	printf("num_times_to_eat:	%d\n", program_data->num_times_to_eat);
	printf("\n");
}

int main(int argc, char **argv)
{
	t_program_data	program_data;
	struct timeval	time;

	memset((void *)&program_data, 0, sizeof(t_program_data));
	memset((void *)&time, 0, sizeof(struct timeval));
	if (!validate_and_get_input(argc, argv, &program_data))
		return (1);
	print_philo_numbers(&program_data);
	if (!create_philos(&program_data))
		return (1);
	return (0);
}
