/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_get_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:43:09 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/13 20:28:46 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// argv[1] = number_of_philosophers
// argv[2] = time_to_die
// argv[3] = time_to_eat
// argv[4] = time_to_sleep
// (argv[5] = number_of_times_each_philosopher_must_eat) - optional argument

static bool	save_input_to_program_data(t_program_data *program_data, char **argv);
static bool	get_number(char *str, int *exit_code);
static int	ft_isdigit(int c);


bool	validate_and_get_input(int argc, char **argv, t_program_data *program_data)
{
	if ((argc != 5 && argc <= 5) || (argc != 6 && argc > 6))
	{
		print_error(TYPE_ERROR, ERR_ARGC);
		print_error(TYPE_HINT, HINT_USAGE);
		return (false);
	}
	if (!save_input_to_program_data(program_data, argv))
		return (false);
	if (argc == 5)
		program_data->meals_to_eat = -1;
	if (program_data->num_philos < 1)
		return (print_error(TYPE_ERROR, ERR_NUM_PHILOS), false);
	return (true);
}	

static bool	save_input_to_program_data(t_program_data *program_data, char **argv)
{
	if (!get_number(argv[1], &program_data->num_philos))
		return (false);
	if (!get_number(argv[2], &program_data->time_to_die))
		return (false);
	if (!get_number(argv[3], &program_data->time_to_eat))
		return (false);
	if (!get_number(argv[4], &program_data->time_to_sleep))
		return (false);
	if (argv[5] && !get_number(argv[5], &program_data->meals_to_eat))
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
		return (print_error(TYPE_ERROR, ERR_POSITIVE_NUM), false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (print_error(TYPE_ERROR, ERR_ONLY_NUM), false);
		temp = result * 10 + (*str++ - '0');
		if (temp > INT_MAX - 1)
			return (print_error(TYPE_ERROR, ERR_NUM_TOO_BIG), false);
		result = temp;
	}
	*number = (int)(result);
	return (true);
}

//checks if the character is (‘0’ - ‘9’).
//returns non-zero for true and 0 for false.
static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
