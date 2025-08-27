/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:32:54 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/26 13:32:55 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfull.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	b;
	size_t	l;

	i = 0;
	b = ft_strlen(big);
	l = ft_strlen(little);
	if (l == 0)
		return ((char *)big);
	if (len <= 0 || b < l)
		return (NULL);
	while (big[i])
	{
		j = 0;
		while (i + j < len && i + j < b && j < l && big[i + j] == little[j])
			j++;
		if (j == len || j == l)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
