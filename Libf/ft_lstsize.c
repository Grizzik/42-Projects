/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:41:36 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/23 14:50:19 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list	**start;
// 	t_list	*m1;
// 	t_list	*m2;
// 	t_list	*m3;
// 	t_list	*m4;
// 	start = &m1;
// 	m1 = ft_lstnew("H");
// 	m2 = ft_lstnew("i");
// 	m3 = ft_lstnew("h");
// 	m4 = ft_lstnew("i");
// 	m1->next = m2;
// 	m2->next = m3;
// 	m3->next = m4;
// 	printf("%d\n", ft_lstsize(m1));
// 	return (0);
// }