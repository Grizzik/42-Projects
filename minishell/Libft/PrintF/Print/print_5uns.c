/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_5uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:44:47 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/26 13:44:48 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfull.h"

int	print_5uns(t_print param, va_list args)
{
	unsigned int	nb;
	int				size;
	char			*nb_utoa;
	char			*to_print;

	nb = (unsigned int)va_arg(args, int);
	nb_utoa = ft_utoa(nb);
	if (nb == 0 && param.precision == 0)
		nb_utoa[0] = '\0';
	size = size_int(param, nb_utoa);
	to_print = malloc(size * sizeof(char));
	if (!to_print)
		return (0);
	fill_int(&to_print, nb_utoa, param, size);
	free(nb_utoa);
	ft_putstr_fd(to_print, param.fd);
	free(to_print);
	return (size - 1);
}
