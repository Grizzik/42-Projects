/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:15:01 by npetitpi          #+#    #+#             */
/*   Updated: 2022/07/26 15:19:11 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	ft_condition(long nb, int i, char *itoa)
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

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
