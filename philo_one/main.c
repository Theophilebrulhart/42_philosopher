/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:44:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/08/12 17:10:46 by theophilebr      ###   ########.fr       */
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
