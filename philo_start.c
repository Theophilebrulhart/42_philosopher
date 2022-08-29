/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:32:32 by theophilebr       #+#    #+#             */
/*   Updated: 2022/08/25 15:24:13 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void *arg)
{
	t_main *main;

	main = (t_main *)arg;
	taking_fork(main, main->thread_id);
	return (0);
}

void	*dead_checker(void *arg)
{
	t_main *main;
	int	i;

	main = (t_main *)arg;
	i = 0;
	while (i < main->state.nbr_philo && !main->dead) 
	{
		philo_dead(main, i);
		i++;
		if (i == main->state.nbr_philo)
			i = 0;
	}
	// if (pthread_mutex_unlock(&main->m_checker) != 0)
	// 	error_exit(main);
	return (0);
}