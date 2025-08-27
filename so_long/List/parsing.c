/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:36:26 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 15:20:55 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	already_sort(t_list	*lst)
{
	t_list	*after;

	after = lst->next;
	while (after && lst->content < after->content)
	{
		lst = after;
		after = after->next;
	}
	if (!after)
		return (0);
	return (1);
}

int	search_dup(t_list *stack)
{
	t_list	*save;

	if (!stack)
		return (0);
	while (stack)
	{
		save = stack->next;
		while (save)
		{
			if (stack->content == save->content)
				return (0);
			save = save->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	arg_ok(char **str)
{
	int	i;
	int	j;

	i = 1;
	if (!ft_int(str))
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-')
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_int(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) >= -2147483648 && ft_atoi(str[i]) <= 2147483647
			&& str[i][0] != '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	sign;
	long	res;
	long	i;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
