/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:05:22 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/05 11:51:13 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# define FORMAT -2
# define SUCCESS 0
# define ERROR_THREAD 1
# define ERROR_ALLOC 2
# define ERROR_TIME 3
# define ERROR_ARG 4
# define EATING 5
# define SLEEPING 6
# define THINKING 7
# define FORK 8
# define DEAD 9
# define CONTINUE 10
# define STOP 11

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_mutex;

typedef struct s_argument
{
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_meals;
}			t_argument;

typedef struct s_table
{
	t_mutex				m_last_meal;
	t_mutex				m_display;
	t_mutex				m_state;
	t_mutex				m_all_alive;
	t_mutex				m_n_meals;
	t_mutex				*forks;
	t_argument			option;
	struct s_philo		*philosophe;
	int					all_alive;
}						t_table;

typedef struct s_philo
{
	int			id;
	int			fork_left;
	int			fork_right;
	int			state;
	int			nb_meals;
	t_table		*table;
	t_time		last_meal;
	t_time		start_time;
	pthread_t	thread;
}				t_philo;

int		check_arg(t_argument *option, int argc, char **argv);
int		error_commande(void);
int		init_table(t_table *table, t_argument option);
void	init_philosophers(t_table *table, t_time time);
long	get_time_stamp(t_time start);
void	print_state(t_philo *philo);
int		waiting(long to_wait, t_table *table);
void	*routine(void *param);
int		all_alive(t_table *table);
int		all_full(t_table *table);
int		all_alive_and_hungry(t_table *table);
void	update_state(t_philo *philo, int state);

#endif
