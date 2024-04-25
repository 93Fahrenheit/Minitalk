/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:59:53 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/04/25 09:05:05 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int check_PID(char *str)
{
    long int secure_overflow;
    int i;
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
    return ((int)secure_overflow);
}
int check_str(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if(!ft_isprint(str[i]))
        {
            ft_putstr("Error, string must only contain printable characters");
            return (-1);
        }
        i++;     
    }
    return (0);
}
void    send_char(char c, int pid)
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
int main(int argc, char **argv)
{
    int pid;
    
    if (argc != 3)
    {
        ft_putstr("Error, this program needs 2 arguments (PID and message)\n");
        return (EXIT_FAILURE);
    }
    pid = check_PID(argv[1]);
    if (pid < 0)
        return (EXIT_FAILURE);
    if (check_str(argv[2]) < 0)
        return EXIT_FAILURE;
    return (EXIT_SUCCESS);
}