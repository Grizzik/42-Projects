/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:35:56 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 17:28:49 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_radx(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstlen(head_a);
	max_bits = ft_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (!((head_a->index >> i) & 1))
				push(stack_b, stack_a, 'b');
			else
				rotate(stack_a, 'a');
		}
		while (ft_lstlen(*stack_b) != 0)
			push(stack_a, stack_b, 'a');
		i++;
	}
}
