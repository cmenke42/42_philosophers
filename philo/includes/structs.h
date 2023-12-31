/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:49:59 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/19 03:36:51 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

typedef struct s_program_data	t_program_data;
typedef struct s_philo			t_philo;

typedef struct s_program_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	long int		start_time;
	pthread_mutex_t	start_simulation_mutex;
	int				num_philo_full;
	pthread_mutex_t	num_philo_full_mutex;
	bool			end_of_simulation;
	pthread_mutex_t	end_of_simulation_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_program_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	long int		last_meal;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_program_data	*program_data;
}				t_philo;

#endif
