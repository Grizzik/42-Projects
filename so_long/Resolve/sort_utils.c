/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:36:08 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 17:29:28 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_index(t_list *stack_a)
{
	t_list	*traveler;
	t_list	*statik;

	statik = stack_a;
	while (statik)
	{
		statik->index = 0;
		traveler = stack_a;
		while (traveler)
		{
			if (statik->content > traveler->content)
				statik->index ++;
			traveler = traveler->next;
		}
		statik = statik->next;
	}
}

int	index_find(t_list *stack, int x)
{
	int		i;
	t_list	*traveler;

	i = 0;
	traveler = stack;
	while (traveler && traveler->index != x)
	{
		i++;
		traveler = traveler->next;
	}
	return (i);
}
