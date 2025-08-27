/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:23:35 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/26 13:57:11 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfull.h"
#include <stdlib.h>

static int	utoxx_size(unsigned int nb)
{
	if (nb < 16)
		return (1);
	return (1 + utoxx_size(nb / 16));
}

char	*ft_utoxx(unsigned int n)
{
	char	*res;
	char	*base;
	int		i;
	int		l;

	l = utoxx_size(n);
	base = "0123456789ABCDEF";
	res = malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	i = l - 1;
	while (i >= 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (res);
}
