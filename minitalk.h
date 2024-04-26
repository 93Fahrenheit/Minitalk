/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:45:21 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/04/26 10:01:46 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H 
	#define MINITALK_h

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <limits.h>


/*    UTILS      */
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void 		ft_putchar(char c);
void 		ft_putstr(char *str);
void 		ft_putnbr(long int nb);

#endif