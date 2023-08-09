/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:49:59 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/09 21:46:53 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

/**
 * @brief Main data structure for the program.
 * @num_philos: The number of philosophers. 1 - N. Also the number of forks.
 * @time_to_die: The time in milliseconds that a philosopher can go without eating.
 * @time_to_eat: The time in milliseconds that a philosopher takes to eat.
 * @time_to_sleep: The time in milliseconds that a philosopher takes to sleep.
 * @num_times_to_eat: The number of times each philosopher must eat.
 */
typedef struct s_philo_data
{
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_times_to_eat;
	long int	start_of_simulation;
}				t_philo_data;


#endif

