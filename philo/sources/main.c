/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:56:15 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/09 20:44:36 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_numbers(t_philo_data *philo_data)
{
	printf("num_philos:		%d\n", philo_data->num_philos);
	printf("time_to_die:		%d\n", philo_data->time_to_die);
	printf("time_to_eat:		%d\n", philo_data->time_to_eat);
	printf("time_to_sleep:		%d\n", philo_data->time_to_sleep);
	printf("num_times_to_eat:	%d\n", philo_data->num_times_to_eat);
}

int main(int argc, char **argv)
{
	t_philo_data	philo_data;

	memset((void *)&philo_data, 0, sizeof(t_philo_data));
	if (!validate_and_get_input(argc, argv, &philo_data))
		return (1);
	print_philo_numbers(&philo_data);
	return (0);
}
