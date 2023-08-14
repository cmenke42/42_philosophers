/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:25:02 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/13 21:54:22 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_state(t_philo *philo_data, char *message)
{
	printf("%ld %d %s\n", get_timestamp_in_ms(philo_data->program_data->start_time),
		philo_data->id + 1, message);
}
