/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:09:57 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/21 17:28:09 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_condition(long nb, int i, char *itoa)
{
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	itoa[i] = '\0';
	while (--i >= 0 && itoa[i] != '-')
	{
		itoa[i] = (nb % 10) + 48;
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*itoa;

	nb = n;
	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	itoa = malloc(sizeof(char) * (i + 1));
	if (!itoa)
		return (NULL);
	ft_bzero(itoa, i);
	ft_condition(nb, i, itoa);
	return (itoa);
}
