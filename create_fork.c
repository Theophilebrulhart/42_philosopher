/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:51:27 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 11:09:45 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_fork(t_main *main)
{
	int	i;

	main->fork = malloc((main->state.nbr_philo + 1) * sizeof(*main->fork));
	if (!main->fork)
		return (1);
	i = 0;
	while (i < main->state.nbr_philo)
	{
		if (pthread_mutex_init(&main->fork[i], NULL) != 0)
			return (2);
		i++;
	}
	return (0);
}
