/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:36:02 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 17:28:53 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_list **stack, char c)
{
	t_list	*after;
	t_list	*head;

	head = *stack;
	after = head->next;
	if (head->index > after->index)
		swap(*stack, c);
}

void	sort_3(t_list **stack, char c)
{
	t_list	*after;
	t_list	*head;

	sort_2(stack, 'a');
	while (already_sort(*stack))
	{
		head = *stack;
		after = head->next;
		if (head->index > after->index)
			swap(*stack, c);
		else
			reverse_rotate(stack, c);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b, int x)
{
	if (index_find(*stack_a, x) < 2)
	{
		while ((*stack_a)->index != x)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != x)
			reverse_rotate(stack_a, 'a');
	}
	push(stack_b, stack_a, 'b');
	sort_3(stack_a, 'a');
	push(stack_a, stack_b, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (index_find(*stack_a, 0) < 3)
	{
		while ((*stack_a)->index != 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != 0)
			reverse_rotate(stack_a, 'a');
	}
	push(stack_b, stack_a, 'b');
	sort_4(stack_a, stack_b, 1);
	push(stack_a, stack_b, 'a');
}

void	short_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstlen(*stack_a) == 2)
		sort_2(stack_a, 'a');
	else if (ft_lstlen(*stack_a) == 3)
		sort_3(stack_a, 'a');
	else if (ft_lstlen(*stack_a) == 4)
		sort_4(stack_a, stack_b, 0);
	else if (ft_lstlen(*stack_a) == 5)
		sort_5(stack_a, stack_b);
}
