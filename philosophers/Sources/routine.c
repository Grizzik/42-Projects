/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:05:58 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/05 11:51:19 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_eating(t_philo *philo)
{
	update_state(philo, FORK);
	pthread_mutex_lock(&(philo->table->forks[philo->fork_left]));
	print_state(philo);
	pthread_mutex_lock(&(philo->table->forks[philo->fork_right]));
	print_state(philo);
	update_state(philo, EATING);
	print_state(philo);
	return (waiting(philo->table->option.time_to_eat, philo->table));
}

static int	start_sleeping(t_philo *philo)
{
	if (!all_alive(philo->table))
		return (STOP);
	update_state(philo, SLEEPING);
	print_state(philo);
	return (waiting(philo->table->option.time_to_sleep, philo->table));
}

static void	routine_one(t_philo *philo)
{
	update_state(philo, FORK);
	pthread_mutex_lock(&(philo->table->forks[philo->fork_left]));
	print_state(philo);
	waiting(philo->table->option.time_to_die, philo->table);
	update_state(philo, DEAD);
	pthread_mutex_unlock(&(philo->table->forks[philo->fork_left]));
}

void	routine_loop(t_philo *philo)
{
	int	status;

	if (philo->fork_left == philo->fork_right)
	{
		routine_one(philo);
		return ;
	}
	status = start_eating(philo);
	pthread_mutex_unlock(&(philo->table->forks[philo->fork_left]));
	pthread_mutex_unlock(&(philo->table->forks[philo->fork_right]));
	if (status == STOP)
		return ;
	pthread_mutex_lock(&(philo->table->m_n_meals));
	philo->nb_meals++;
	pthread_mutex_unlock(&(philo->table->m_n_meals));
	if (start_sleeping(philo) == STOP)
		return ;
	update_state(philo, THINKING);
	print_state(philo);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (all_alive_and_hungry(philo->table) == STOP)
			break ;
		routine_loop(philo);
		usleep(100);
	}
	return (NULL);
}
