/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:46:03 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/08/25 17:50:35 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;
struct	s_philo
{
	int			philo_id;
	int			left_fork;
	int			right_fork;
	int			nbr_eat;
	int			eating;
	long long	die_time;
	pthread_t	thread;
};

typedef struct s_state	t_state;
struct	s_state
{
	int			eat_time;
	int			sleep_time;
	long long	die_time;
	int			max_eat;
	int			nbr_philo;
};

typedef struct s_main	t_main;
struct s_main
{
	t_philo			*philo;
	t_state 		state;
	int				thread_id;
	long long		t0;
	int				all_eat;
	int				dead;
	pthread_t		checker;
	pthread_mutex_t	*fork;
	pthread_mutex_t write;
	pthread_mutex_t	eat;
	pthread_mutex_t	m_checker;
};

int			initialize(t_main *main, char **argv);
int			ft_atoi(const char *s);
void		create_philo(t_main *main);
int			create_fork(t_main *main);
void		error_exit(t_main *main);
void		*start(void *arg);
int			create_threads(t_main *main);
void		taking_fork(t_main *main, int i);
void		philo_eat(t_main *main, int i);
void    	write_state(t_main *main, int i, int state);
long long	time_to_die(long long die_time);
long long	get_time();
void		*dead_checker(void *arg);
void		philo_dead(t_main *main, int i);
void		my_usleep(int time, t_main *main);

#endif