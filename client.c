/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:59:53 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/04/28 18:18:02 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_pid(char *str)
{
	long int	secure_overflow;
	int			i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr("Error, PID can't contain characters\n");
			return (-1);
		}
		i++;
	}
	secure_overflow = ft_atoi(str);
	if (secure_overflow > INT_MAX || secure_overflow <= 0)
	{
		ft_putstr("Error, PID does not exist or is too large\n");
		return (-1);
	}
	return (secure_overflow);
}

void	send_char(char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		usleep(150);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	long int	pid;
	int			i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("Error, this program needs 2 arguments (PID and message)\n");
		return (EXIT_FAILURE);
	}
	pid = check_pid(argv[1]);
	if (pid < 0)
		return (EXIT_FAILURE);
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (EXIT_SUCCESS);
}
