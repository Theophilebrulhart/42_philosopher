/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:46:03 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/07/27 16:35:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo	t_philo;
struct	s_philo
{
	int	philo_id;
	int	left_fork;
	int	right_fork;
};

#endif