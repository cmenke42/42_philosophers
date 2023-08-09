/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:41:22 by cmenke            #+#    #+#             */
/*   Updated: 2023/08/09 19:38:15 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print(long int number, int digits, long int divisor, int fd);
static void	ft_putchar_fd(char c, int fd);

//counts the digits
void	ft_putnbr_fd(int n, int fd)
{
	int			digits;
	long int	divisor;
	long int	number;

	digits = 0;
	divisor = 1;
	number = n;
	while (number != number % divisor)
	{
		digits++;
		divisor *= 10;
	}
	ft_print(number, digits, divisor / 10, fd);
}

//prints the number to the filedescriptor
static void	ft_print(long int number, int digits, long int divisor, int fd)
{
	if (number == 0)
		ft_putchar_fd('0', fd);
	else if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number *= -1;
	}
	while (digits > 0)
	{
		ft_putchar_fd(((number / divisor) % 10) + '0', fd);
		divisor /= 10;
		digits--;
	}
}

//writes char c to the filedescriptor fd
static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
