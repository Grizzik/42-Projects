/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:35:23 by npetitpi          #+#    #+#             */
/*   Updated: 2022/11/07 17:34:45 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

int		ft_max_bits(t_list **stack_a);

void	insert_last(t_list	**lst, int val, int index);
void	delete_node(t_list	**lst, int val);
t_list	*find_prev_elem(t_list *lst, int val);
t_list	*make_list(int ac, char **av);

t_list	*ft_lstnew(int val, int index);
size_t	ft_lstlen(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	free_list(t_list **lst);

int		already_sort(t_list	*lst);
int		search_dup(t_list *stack);
int		arg_ok(char **str);
int		ft_int(char **str);
long	ft_atoi(char *str);

int		swap(t_list *stack, char c);
int		rotate(t_list **stack, char c);
int		reverse_rotate(t_list **stack, char c);
int		push(t_list **stack1, t_list **stack2, char c);

int		ft_ss(t_list *stack_a, t_list *stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);

void	sort_radx(t_list **stack_a, t_list **stack_b);

void	sort_2(t_list **stack, char c);
void	sort_3(t_list **stack, char c);
void	sort_4(t_list **stack_a, t_list **stack_b, int x);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	short_sort(t_list **stack_a, t_list **stack_b);

void	ft_index(t_list *stack_a);
int		index_find(t_list *stack, int x);

int		ft_error(int ac, char **av);
void	print_index(t_list **lst);
void	print_list(t_list **lst);
void	ft_putendl_fd(char *str, int fd);
int		main(int ac, char **av);

#endif