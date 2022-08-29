/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:03:50 by theophilebr       #+#    #+#             */
/*   Updated: 2022/08/25 17:52:06 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->state.nbr_philo)
	{
		pthread_mutex_destroy(&main->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	pthread_mutex_destroy(&main->m_checker);
}

void	error_exit(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->state.nbr_philo)
	{
		pthread_detach(&main->philo->thread[i]);
		i++;
	}
	my_usleep(1000, main);
	if (main->philo)
		free(main->philo);
	if (main->fork)
		free(main->fork);
		destroy_mutex(main);
	exit (0);
}