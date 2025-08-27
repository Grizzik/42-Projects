/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:33:13 by npetitpi          #+#    #+#             */
/*   Updated: 2022/05/11 17:40:04 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*oscour;

	oscour = malloc(nmemb * size);
	if (!oscour)
		return (NULL);
	ft_bzero (oscour, nmemb * size);
	return ((void *)oscour);
}
