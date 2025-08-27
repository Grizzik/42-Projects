/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:35:32 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 17:28:32 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_ss(t_list *stack_a, t_list *stack_b)
{
	if (swap(stack_a, 's') == -1 || swap(stack_b, 's') == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a, 's') == -1
		|| reverse_rotate(stack_b, 's') == -1)
		return (-1);
	ft_putendl_fd("rrr", 1);
	return (0);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if ((rotate(stack_a, 's') == -1)
		|| (rotate(stack_b, 's') == -1))
		return (-1);
	ft_putendl_fd("rr", 1);
	return (0);
}
