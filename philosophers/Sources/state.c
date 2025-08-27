/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:06:06 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/05 11:51:20 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_state(t_philo *philo, int state)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&(table->m_state));
	if (philo->state != DEAD)
	{
		philo->state = state;
		if (state == EATING)
		{
			pthread_mutex_lock(&(table->m_last_meal));
			gettimeofday(&(philo->last_meal), NULL);
			pthread_mutex_unlock(&(table->m_last_meal));
		}
		pthread_mutex_unlock(&(table->m_state));
		return ;
	}
	pthread_mutex_unlock(&(table->m_state));
}

static void	state_msg(t_philo *philo, long time_stamp, int id,
	int *print_end)
{
	int	state;

	pthread_mutex_lock(&(philo->table->m_state));
	state = philo->state;
	pthread_mutex_unlock(&(philo->table->m_state));
	if (all_full(philo->table))
	{
		printf("\033[32;7m  -- Everyone has eaten enough --   \033[04m\n");
		*print_end = 1;
	}
	else if (state == DEAD)
	{
		printf("%5ld %d \033[35;5m died \033[00m\n", time_stamp, id);
		*print_end = 1;
	}
	else if (state == FORK && all_alive(philo->table))
		printf("%5ld %d has taken a fork\n", time_stamp, id);
	else if (state == EATING)
		printf("%5ld %d is eating\n", time_stamp, id);
	else if (state == SLEEPING)
		printf("%5ld %d is sleeping\n", time_stamp, id);
	else if (state == THINKING)
		printf("%5ld %d is thinking\n", time_stamp, id);
}

void	print_state(t_philo *philo)
{
	static int	print_end;
	long		time_stamp;
	int			id;

	time_stamp = get_time_stamp(philo->start_time);
	id = philo->id;
	pthread_mutex_lock(&(philo->table->m_display));
	if (!print_end)
		state_msg(philo, time_stamp, id, &print_end);
	pthread_mutex_unlock(&(philo->table->m_display));
}
