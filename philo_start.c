/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:32:32 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 11:12:16 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void *arg)
{
	t_main	*main;

	main = (t_main *)arg;
	taking_fork(main, main->thread_id);
	return (0);
}

void	*dead_checker(void *arg)
{
	t_main	*main;
	int		i;

	main = (t_main *)arg;
	i = 0;
	while (i < main->state.nbr_philo && !main->dead)
	{
		philo_dead(main, i);
		i++;
		if (i == main->state.nbr_philo)
			i = 0;
	}
	return (0);
}
