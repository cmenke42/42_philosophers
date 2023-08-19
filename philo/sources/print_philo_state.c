/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:25:02 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 03:44:51 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_state(t_philo *philo_data, char *message, bool is_dead)
{
	pthread_mutex_lock(&philo_data->program_data->end_of_simulation_mutex);
	if (!philo_data->program_data->end_of_simulation || is_dead)
	{
		printf("%ld %d %s\n",
			get_timestamp_in_ms(philo_data->program_data->start_time),
			philo_data->id + 1, message);
	}
	pthread_mutex_unlock(&philo_data->program_data->end_of_simulation_mutex);
}
