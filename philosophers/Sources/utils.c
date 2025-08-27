/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:06:22 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/05 11:51:23 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_commande(void)
{
	printf("commande:\n./philo n time_to_die time_to_eat \
		time_to_sleep [n_meals]\n\n");
	printf("description:\n");
	printf("  n_philos       nombre de philosophes à table\n");
	printf("  time_to_die    temps maximum entre deux repas avant de mourir\n");
	printf("  time_to_eat    temps passé à manger\n");
	printf("  time_to_sleep  temps passé à dormir\n");
	printf("  n_meals        nombre de repas avant la fin de la simulation\n");
	return (SUCCESS);
}

static int	ft_atoi(char *nptr)
{
	long	atoi;
	int		i;

	atoi = 0;
	i = 0;
	if (nptr[0] < '0' || nptr[0] > '9')
		return (FORMAT);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		atoi = 10 * atoi + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0' || atoi > 2147483647 || i > 10)
		return (FORMAT);
	return ((int)atoi);
}

int	check_arg(t_argument *option, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (ERROR_ARG);
	option->n_philos = ft_atoi(av[1]);
	option->time_to_die = ft_atoi(av[2]);
	option->time_to_eat = ft_atoi(av[3]);
	option->time_to_sleep = ft_atoi(av[4]);
	option->n_meals = -1;
	if (ac == 6)
		option->n_meals = ft_atoi(av[5]);
	if (option->n_philos == FORMAT || option->time_to_die == FORMAT
		|| option->time_to_eat == FORMAT || option->time_to_sleep == FORMAT
		|| option->n_meals == FORMAT)
		return (ERROR_ARG);
	return (SUCCESS);
}
