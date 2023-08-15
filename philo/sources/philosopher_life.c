/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:08:30 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/15 22:16:49 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_philo *philo_data);

void	*philosopher_life(void *philo)
{
	t_philo	*philo_data;

	philo_data = (t_philo *)philo;
	while (philo_data->program_data->end_of_simulation == false) //mutex!
	{
		philo_eat(philo_data);
		philo_sleep(philo_data);
		print_philo_state(philo_data, MSG_THINK);
	}
	return (NULL);
}


static void	philo_sleep(t_philo *philo_data)
{
	print_philo_state(philo_data, MSG_SLEEP);
	waiting_in_ms(philo_data->program_data->time_to_sleep, 0);
}

//to reduce the delay of usleep
void	waiting_in_ms(int time, long int last_meal_time)
{
	long int start_time;

	if (last_meal_time == 0)
		start_time = get_time_in_ms();
	else
		start_time = last_meal_time;
	while (get_time_in_ms() - start_time < time)
		usleep(1000);
}
