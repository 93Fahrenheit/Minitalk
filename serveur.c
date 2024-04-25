/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:00:01 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/04/25 08:57:32 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    receive_sig(sig_number)
{
    static char	c;
	static int	byte;

	if (sig_number == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig_number == SIGUSR2)
		c = (c << 1);
	byte++;
	if (byte == 8)
	{
		write(1, &c, 1);
		c = 0;
		byte = 0;
	}
}

int main(void)
{
    int pid;
    
    pid = getpid();
    signal(SIGUSR1, receive_sig);
    signal(SIGUSR2, receive_sig)
    ft_putstr("PID :");
    ft_putnbr(pid);
    ft_putstr("\n");
    while (pause() != -1)
        ;
    return (0);
}