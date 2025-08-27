/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:28:09 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/25 12:25:14 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	atoi;
	int	minus;

	atoi = 0;
	minus = 1;
	while ((*nptr != '\0' && (*nptr >= 9 && *nptr <= 13)) || *nptr == 32)
		++nptr;
	if (*nptr == '-')
		minus = -1;
	if (*nptr == '-' || *nptr == '+')
		++nptr;
	while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
	{
		atoi = atoi * 10 + (*nptr - 48);
		++nptr;
	}
	return (atoi * minus);
}
