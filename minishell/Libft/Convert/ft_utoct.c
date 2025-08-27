/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:23:28 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/26 13:57:20 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfull.h"
#include <stdlib.h>

static int	itoa_size(unsigned int nb, short int sg, unsigned int base)
{
	if (nb < base)
		return (1 + (sg == -1));
	return (1 + itoa_size(nb / base, sg, base));
}

char	*ft_utoct(unsigned int n)
{
	char	*res;
	char	*base;
	int		i;
	int		l;

	l = itoa_size(n, 1, 8);
	base = "01234567";
	res = malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	i = l - 1;
	while (i >= 0)
	{
		res[i] = base[n % 8];
		n = n / 8;
		i--;
	}
	return (res);
}
