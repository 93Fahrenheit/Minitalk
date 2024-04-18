/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:59:53 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/04/18 05:20:12 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
    pid_t pid;
    long int test;
    
    if (argc != 3)
    {
        printf("Error, this program needs 3 arg\n");
        return (0);
    }
    else   
    {
        test = ft_atoi(argv[1]);
        if (test > INT_MAX || test < INT_MIN)
        {
            printf("Error pid does not exist or is too large\n");
            return (0);
        }
        else
        {
            pid = test;
            printf("%d\n", pid);
        }    
    }
    printf("%d\n", pid);
}