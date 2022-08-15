/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:58:17 by theophilebr       #+#    #+#             */
/*   Updated: 2022/08/15 13:38:15 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time()
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	time_to_die(t_main *main, long long die_time)
{
	//float time;
	(void)main;

	if (die_time > 0)
		return (get_time() - die_time);
	return (-1);
}