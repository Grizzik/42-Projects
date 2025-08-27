/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:38:45 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/23 14:25:56 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

// int	main()
// {
// 	t_list	*new;
// 	new = ft_lstnew("Coucou");
// 	printf("%s\n", (char *)new->content);
// 	return (0);
// }