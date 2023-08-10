/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:33:17 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 20:59:01 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//to reduce the delay of usleep
void	waiting_in_ms(int time, long int last_meal_time)
{
	long int start_time;

	if (last_meal_time == 0)
		start_time = get_time_in_ms();
	else
		start_time = last_meal_time;
	while (get_time_in_ms() - start_time < time)
		usleep((useconds_t)1000);
}
