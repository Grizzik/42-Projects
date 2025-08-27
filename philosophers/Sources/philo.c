/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:05:50 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/05 11:51:18 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers(t_table *table, t_time time)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->option.n_philos)
	{
		philo = &(table->philosophe[i]);
		philo->fork_left = i;
		philo->fork_right = i + 1;
		if (i + 1 == table->option.n_philos)
		{
			philo->fork_left = 0;
			philo->fork_right = i;
		}
		philo->state = THINKING;
		philo->last_meal = time;
		philo->start_time = time;
		philo->nb_meals = 0;
		philo->id = i + 1;
		philo->table = table;
	}
}

int	all_full(t_table *table)
{
	int	i;
	int	tot_meals;
	int	philo_meals;

	i = -1;
	tot_meals = table->option.n_meals;
	while (++i < table->option.n_philos)
	{
		pthread_mutex_lock(&(table->m_n_meals));
		philo_meals = table->philosophe[i].nb_meals;
		pthread_mutex_unlock(&(table->m_n_meals));
		if (philo_meals < tot_meals || tot_meals == -1)
			return (0);
	}
	return (1);
}

int	all_alive(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->option.n_philos)
	{
		philo = table->philosophe + i;
		pthread_mutex_lock(&(table->m_last_meal));
		if (get_time_stamp(philo->last_meal) > table->option.time_to_die)
		{
			pthread_mutex_unlock(&(table->m_last_meal));
			pthread_mutex_lock(&(table->m_state));
			philo->state = DEAD;
			pthread_mutex_unlock(&(table->m_state));
			pthread_mutex_lock(&(table->m_all_alive));
			table->all_alive = 0;
			pthread_mutex_unlock(&(table->m_all_alive));
			print_state(philo);
			return (STOP);
		}
		pthread_mutex_unlock(&(table->m_last_meal));
	}
	return (CONTINUE);
}

int	all_alive_and_hungry(t_table *table)
{
	if (all_alive(table) == STOP)
		return (STOP);
	if (all_full(table) == 1)
		return (STOP);
	return (CONTINUE);
}
