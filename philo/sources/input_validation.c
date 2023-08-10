/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:16:40 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/10 18:42:06 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// argv[1] = number_of_philosophers
// argv[2] = time_to_die
// argv[3] = time_to_eat
// argv[4] = time_to_sleep
// (argv[5] = number_of_times_each_philosopher_must_eat) - optional argument

static bool	save_input_to_philo_data(t_program_data *philo_data, char **argv);
static bool	get_number(char *str, int *exit_code);


bool validate_and_get_input(int argc, char **argv, t_program_data *philo_data)
{
	if ((argc != 5 && argc <= 5) || (argc != 6 && argc > 6))
	{
		ft_putstr_fd("Error: Incorrect number of arguments\n", STDERR_FILENO);
		ft_putstr_fd("The correct number of arguments is 4 or 5\n", STDERR_FILENO);
		ft_putstr_fd("The correct format is: ./philo number_of_philosophers time_to_die(ms) time_to_eat(ms) time_to_sleep(ms) [number_of_times_each_philosopher_must_eat]\n", STDERR_FILENO);
		return (false);
	}
	if (!save_input_to_philo_data(philo_data, argv))
		return (false);
	if (argc == 5)
		philo_data->num_times_to_eat = -1;
	if (philo_data->num_philos < 1)
		return (ft_putstr_fd("Error: There must be at least 1 philosopher\n", STDERR_FILENO), false);
	return (true);
}

static bool	save_input_to_philo_data(t_program_data *philo_data, char **argv)
{
	if (!get_number(argv[1], &philo_data->num_philos))
		return (false);
	if (!get_number(argv[2], &philo_data->time_to_die))
		return (false);
	if (!get_number(argv[3], &philo_data->time_to_eat))
		return (false);
	if (!get_number(argv[4], &philo_data->time_to_sleep))
		return (false);
	if (argv[5] && !get_number(argv[5], &philo_data->num_times_to_eat))
		return (false);
	return (true);
}

static bool	get_number(char *str, int *number)
{
	unsigned long int	temp;
	unsigned long int	result;

	result = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (ft_putstr_fd("Error: Only positive numbers are allowed\n", STDERR_FILENO), false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (ft_putstr_fd("Error: Only numbers are allowed\n", STDERR_FILENO), false);
		temp = result * 10 + (*str++ - '0');
		if (temp > INT_MAX - 1)
			return (ft_putstr_fd("Error: Number is too large\n", STDERR_FILENO), false);
		result = temp;
	}
	*number = (int)(result);
	return (true);
}
