/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:56:15 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 21:20:25 by cmenke           ###   ########.fr       */
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

	memset((void *)&program_data, 0, sizeof(t_program_data));
	if (!validate_and_get_input(argc, argv, &program_data))
		return (1);
	print_philo_numbers(&program_data);
	program_data.start_of_simulation = get_time_in_ms();
	pthread_mutex_init(&program_data.time_of_last_meal_mutex, NULL); //error check?
	pthread_mutex_init(&program_data.print_mutex, NULL); //error check?
	if (!create_philos(&program_data))
		return (1);
	while (1)
		;
	usleep(1000000);
	return (0);
}
