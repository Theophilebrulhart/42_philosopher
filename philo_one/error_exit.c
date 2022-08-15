/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:03:50 by theophilebr       #+#    #+#             */
/*   Updated: 2022/08/15 14:16:46 by theophilebr      ###   ########.fr       */
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
	destroy_mutex(main);
	while (i < main->state.nbr_philo)
	{
		pthread_detach(&main->philo->thread[i]);
		i++;
	}
	if (main->philo)
		free(main->philo);
	if (main->fork)
		free(main->fork);
	exit (0);
}