/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:34:14 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 11:12:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	convert;

	i = 0;
	sign = 1;
	convert = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		convert *= 10;
		convert = convert + (s[i] - '0');
		i++;
	}
	return (convert * sign);
}

void	my_usleep(int time, t_main *main)
{
	long long	t;

	t = get_time() * 1000;
	while (!main->dead)
	{
		if (get_time() * 1000 - t >= time)
			break ;
		usleep(500);
	}
}
