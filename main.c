/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:44:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/09/01 11:27:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	main.t0 = get_time();
	main.dead = 0;
	main.all_eat = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (initialize(&main, argv))
		return (0);
	if (create_fork(&main))
		error_exit(&main);
	if (create_threads(&main))
		error_exit(&main);
	return (0);
}
