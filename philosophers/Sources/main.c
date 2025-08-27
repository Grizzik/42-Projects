/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:05:42 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/05 11:51:17 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_argument	option;
	t_table		table;

	if (check_arg(&option, argc, argv))
		return (error_commande());
	return (init_table(&table, option));
}
