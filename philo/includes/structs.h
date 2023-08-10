/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:49:59 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 15:12:46 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

typedef struct s_one_philo t_one_philo;

/**
 * @brief Main data structure for the program.
 * @num_philos: The number of philosophers. 1 - N. Also the number of forks.
 * @time_to_die: The time in milliseconds that a philosopher can go without eating.
 * @time_to_eat: The time in milliseconds that a philosopher takes to eat.
 * @time_to_sleep: The time in milliseconds that a philosopher takes to sleep.
 * @num_times_to_eat: The number of times each philosopher must eat.
 */
typedef struct s_program_data
{
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_times_to_eat;
	long int	start_of_simulation;
	t_one_philo	**philos;
}				t_program_data;

typedef struct	s_shared_vars
{

}				t_shared_vars;

typedef struct	s_one_philo
{
	int				id;
	long int		time_of_last_meal;
	int				meals_left;
	t_program_data	program_data;
}				t_one_philo;

#endif

