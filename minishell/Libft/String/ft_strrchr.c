/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:32:58 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/26 13:32:59 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfull.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;
	size_t	i;
	char	*str;
	char	*ret;

	n = ft_strlen(s);
	i = 0;
	str = (char *)s;
	ret = NULL;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			ret = str + i;
		i++;
	}
	if (c == 0)
		return (str + n);
	return (ret);
}
