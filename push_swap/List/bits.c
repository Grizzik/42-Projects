/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:30:06 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 17:27:28 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max_bits(t_list **stack_a)
{
	t_list	*traveler;
	int		max;
	int		max_bits;

	traveler = *stack_a;
	max = traveler->index;
	max_bits = 0;
	while (traveler)
	{
		if (traveler->index > max)
			max = traveler->index;
		traveler = traveler->next;
	}
	while ((max >> max_bits) != 0)
		max_bits ++;
	return (max_bits);
}
