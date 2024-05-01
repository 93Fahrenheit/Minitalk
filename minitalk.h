/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:45:21 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/04/30 06:53:20 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(long int nb);

#endif