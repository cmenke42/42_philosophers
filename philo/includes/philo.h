/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:59:08 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 20:46:19 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

# include "structs.h"
# include "colors.h"




//input_validation.c
bool validate_and_get_input(int argc, char **argv, t_program_data *philo_data);

//
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);

//get_time.c
long int	get_time_in_ms(void);
int			get_timestamp_in_ms(long int start_time);

//create_philos.c
bool	create_philos(t_program_data *program_data);
void	free_philos(t_program_data *program_data);

//philo_life.c
void	*philo_life(void *philo);

//helpers.c
void	print_data_of_one_philo(t_one_philo *philo); //delete

//waiting.c
void	waiting_in_ms(int time, long int last_meal_time);

//print_message.c
void	print_message(t_one_philo *philo, char *message);
#endif