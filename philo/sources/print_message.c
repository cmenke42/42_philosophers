/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:44:14 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 21:17:30 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_one_philo *philo_data, char *message)
{
	pthread_mutex_lock(&(philo_data->program_data.print_mutex));
	printf("%d %d %s\n", get_timestamp_in_ms(philo_data->program_data.start_of_simulation),
		philo_data->id, message);
	pthread_mutex_unlock(&(philo_data->program_data.print_mutex));
}
