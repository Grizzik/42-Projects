/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moovs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:35:51 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 17:28:29 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_list *stack, char c)
{
	int		tmp_content;
	int		tmp_index;
	t_list	*tmp_next;

	if (ft_lstlen(stack) <= 1)
		return (-1);
	tmp_content = stack->content;
	tmp_index = stack->index;
	tmp_next = stack->next;
	stack->content = tmp_next->content;
	stack->index = tmp_next->index;
	stack = stack->next;
	stack->content = tmp_content;
	stack->index = tmp_index;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
	return (1);
}

int	rotate(t_list **stack, char c)
{
	int		tmp;
	int		tmp_index;
	t_list	*prev;

	if (ft_lstlen(*stack) <= 1)
		return (-1);
	tmp = (*stack)->content;
	tmp_index = (*stack)->index;
	prev = (*stack);
	(*stack) = (*stack)->next;
	free(prev);
	insert_last(stack, tmp, tmp_index);
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
	return (1);
}

int	reverse_rotate(t_list **stack, char c)
{
	t_list	*last_node;
	t_list	*before_last_node;

	if (ft_lstlen(*stack) <= 1)
		return (-1);
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	before_last_node = find_prev_elem(*stack, last_node->content);
	before_last_node->next = NULL;
	*stack = last_node;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
	return (1);
}

int	push(t_list **stack1, t_list **stack2, char c)
{
	t_list	*new;

	if (ft_lstlen(*stack2) == 0)
		return (-1);
	new = ft_lstnew((*stack2)->content, (*stack2)->index);
	new->next = *stack1;
	*stack1 = new;
	delete_node(stack2, (*stack2)->content);
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
	return (1);
}
