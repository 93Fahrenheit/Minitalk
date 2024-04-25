/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:00:01 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/04/25 07:24:12 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
    int pid;
    
    pid = getpid();
    printf("Le PID du serveur est : %d\n", pid);
    while (pause() != -1)
        ;
    return (0);
}

