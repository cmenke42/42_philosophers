/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:32:45 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 04:28:26 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//to reduce the delay of usleep
void	waiting_in_ms(int time, long int last_meal_time)
{
	long int	start_time;

	if (last_meal_time == 0)
		start_time = get_time_in_ms();
	else
		start_time = last_meal_time;
	while (get_time_in_ms() - start_time < time)
		usleep(1000);
}

long int	get_timestamp_in_ms(long int start_time)
{
	return ((get_time_in_ms() - start_time));
}

long int	get_time_in_ms(void)
{
	struct timeval	time;

	memset((void *)&time, 0, sizeof(struct timeval));
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
