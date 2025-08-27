/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:36:34 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 15:25:32 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int ac, char **av)
{
	t_list	*stack;

	if (!arg_ok(av))
		return (write(2, "Error\n", 6), 0);
	if (ac <= 2)
		return (0);
	stack = make_list(ac, av);
	if (!search_dup(stack))
		return (free_list(&stack), write(2, "Error\n", 6), 0);
	if (!already_sort(stack))
		return (free_list(&stack), 0);
	return (free_list(&stack), 1);
}

void	print_index(t_list **lst)
{
	t_list	*ptr;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		printf("%i\n", ptr->index);
		ptr = ptr->next;
	}
	printf("\n");
}

void	print_list(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !lst)
		return ;
	printf("\n");
	tmp = *lst;
	while (tmp)
	{
		printf("%i\n", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

void	ft_putendl_fd(char *str, int fd)
{
	while (*str)
	{
		write(1, str, fd);
		str++;
	}
	write(1, "\n", fd);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (!ft_error(ac, av))
		return (0);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = make_list(ac, av);
	*stack_b = NULL;
	if (ft_lstlen(*stack_a) <= 5)
		short_sort(stack_a, stack_b);
	else
		sort_radx(stack_a, stack_b);
	free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
