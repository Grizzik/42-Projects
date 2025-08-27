/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:05:34 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/05 11:51:15 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	free_all(t_table *table, int err)
{
	int	i;

	i = -1;
	while (++i < table->option.n_philos)
		pthread_mutex_destroy(&(table->forks[i]));
	pthread_mutex_destroy(&(table->m_display));
	pthread_mutex_destroy(&(table->m_all_alive));
	pthread_mutex_destroy(&(table->m_state));
	pthread_mutex_destroy(&(table->m_n_meals));
	if (table->forks)
		free(table->forks);
	if (table->philosophe)
		free(table->philosophe);
	return (err);
}

static int	init_table_bis(t_table *table, t_argument option, t_time time)
{
	int		i;
	t_philo	*philo;

	init_philosophers(table, time);
	i = 0;
	while (i < option.n_philos)
	{
		philo = table->philosophe + i;
		if (pthread_create(&(philo->thread), NULL, &routine, philo))
			return (free_all(table, ERROR_THREAD));
		i += 2;
		if (i >= option.n_philos && i % 2 == 0)
			i = 1;
		usleep(1500);
	}
	while (all_alive_and_hungry(table) == CONTINUE)
		usleep(100);
	i = -1;
	while (++i < option.n_philos)
	{
		philo = table->philosophe + i;
		if (pthread_join(philo->thread, NULL))
			return (free_all(table, ERROR_THREAD));
	}
	return (free_all(table, SUCCESS));
}

static void	init_global_mutex(t_table *table)
{
	pthread_mutex_init(&(table->m_display), NULL);
	pthread_mutex_init(&(table->m_all_alive), NULL);
	pthread_mutex_init(&(table->m_state), NULL);
	pthread_mutex_init(&(table->m_n_meals), NULL);
	pthread_mutex_init(&(table->m_last_meal), NULL);
}

int	init_table(t_table *table, t_argument option)
{
	int		i;
	t_time	time;

	if (gettimeofday(&time, NULL))
		return (ERROR_TIME);
	table->philosophe = malloc(sizeof(t_philo) * option.n_philos);
	table->forks = malloc(sizeof(t_mutex) * option.n_philos);
	table->option = option;
	table->all_alive = 1;
	if (!table->philosophe || !table->forks)
		return (free_all(table, ERROR_ALLOC));
	i = -1;
	while (++i < option.n_philos)
		pthread_mutex_init(&(table->forks[i]), NULL);
	init_global_mutex(table);
	return (init_table_bis(table, option, time));
}
