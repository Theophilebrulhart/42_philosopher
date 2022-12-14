/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:46:56 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 11:09:39 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_main *main, int i)
{
	long long	time;

	if (main->philo[i].eating == 1)
		return ;
	time = time_to_die(main->philo[i].die_time);
	if (time == -1)
		error_exit(main);
	if (time > main->state.die_time)
	{
		main->dead = 1;
		write_state(main, i, 5);
		error_exit(main);
	}
}

void	philo_sleep(t_main *main, int i)
{
	write_state(main, i, 3);
	my_usleep(main->state.sleep_time * 1000, main);
	write_state(main, i, 4);
	taking_fork(main, i);
}

void	drop_fork(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->fork[main->philo[i].left_fork]) != 0)
		error_exit(main);
	if (pthread_mutex_unlock(&main->fork[main->philo[i].right_fork]) != 0)
		error_exit(main);
}

void	max_eat_time(t_main *main, int i)
{
	main->philo[i].nbr_eat++;
	if (main->philo[i].nbr_eat == main->state.max_eat)
		main->all_eat++;
	if (main->all_eat == main->state.nbr_philo)
	{
		write_state(main, i, 6);
		error_exit(main);
	}
}

void	taking_fork(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->fork[main->philo[i].right_fork]) != 0)
		error_exit(main);
	write_state(main, i, 1);
	if (pthread_mutex_lock(&main->fork[main->philo[i].left_fork]) != 0)
		error_exit(main);
	write_state(main, i, 1);
	write_state(main, i, 2);
	main->philo[i].eating = 1;
	main->philo[i].die_time = get_time();
	my_usleep(main->state.eat_time * 1000, main);
	if (pthread_mutex_lock(&main->eat) != 0)
		error_exit(main);
	main->philo[i].eating = 0;
	if (pthread_mutex_unlock(&main->eat) != 0)
		error_exit(main);
	if (main->state.max_eat > 0)
		max_eat_time(main, i);
	drop_fork(main, i);
	philo_sleep(main, i);
}
