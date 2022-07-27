/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:44:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/07/27 16:29:45 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc != 5 && argc != 6)
		return (1);
	printf("it works\n");
	return (0);
}
