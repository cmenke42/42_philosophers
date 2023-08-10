/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:32:45 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 20:43:18 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_in_ms(void)
{
	struct timeval	time;

	memset((void *)&time, 0, sizeof(struct timeval));
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	get_timestamp_in_ms(long int start_time)
{
	return ((int)(get_time_in_ms() - start_time));
}

