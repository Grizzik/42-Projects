/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:04:47 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/21 17:49:20 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen((char *)s) <= start)
		return (ft_strdup(""));
	if (len > start && start != 1)
		dest = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
	{
		return (NULL);
	}
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
