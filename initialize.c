/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:23:01 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 11:42:20 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_main *main)
{
	int	i;

	main->philo = malloc(main->state.nbr_philo * sizeof(*main->philo));
	if (!main->philo)
		exit (1);
	i = 0;
	while (i < main->state.nbr_philo)
	{
		main->philo[i].philo_id = i;
		main->philo[i].left_fork = i + 1;
		main->philo[i].right_fork = i;
		main->philo[i].nbr_eat = 0;
		main->philo[i].die_time = get_time();
		if (i == main->state.nbr_philo - 1)
			main->philo[i].left_fork = 0;
		i++;
	}
}

int	initialize(t_main *main, char **argv)
{
	main->state.nbr_philo = ft_atoi(argv[1]);
	main->state.die_time = ft_atoi(argv[2]);
	main->state.eat_time = ft_atoi(argv[3]);
	main->state.sleep_time = ft_atoi(argv[4]);
	if (main->state.nbr_philo < 0 || main->state.die_time < 0
		|| main->state.eat_time < 0 || main->state.sleep_time < 0)
		return (1);
	if (argv[5])
	{
		main->state.max_eat = ft_atoi(argv[5]);
		if (main->state.max_eat <= 0)
			return (1);
	}
	else
		main->state.max_eat = -1;
	create_philo(main);
	return (0);
}
