/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:30:42 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/24 15:52:27 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src1;
	char	*dest1;
	size_t	i;

	i = 0;
	src1 = (char *)src;
	dest1 = (char *)dest;
	if (dest1 > src1)
	{
		while (n > 0)
		{
			n--;
			dest1[n] = src1[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
