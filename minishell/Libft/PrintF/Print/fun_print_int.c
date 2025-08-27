/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_print_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:44:21 by npetitpi          #+#    #+#             */
/*   Updated: 2023/10/26 13:59:43 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfull.h"

void	fill_int_easy(char **to_print, char *nb, int size)
{
	int		i;

	i = -1;
	while (++i < size - 1)
		(*to_print)[i] = nb[i];
}

void	fill_int(char **to_print, char *nb, t_print param, int size)
{
	int		prec;

	prec = (int)ft_strlen(nb) - (nb[0] == '-');
	if (param.align && param.precision > prec)
		fill_int_left_p(to_print, nb, param, size);
	else if (param.align)
		fill_int_left(to_print, nb, size);
	else if (param.precision > prec)
		fill_int_right_p(to_print, nb, param, size);
	else if (param.precision >= 0)
		fill_int_right(to_print, nb, size);
	else if (!param.zero && param.field >= 0)
		fill_int_right(to_print, nb, size);
	else if (param.zero && param.field >= 0)
		fill_int_zero(to_print, nb, size);
	else
		fill_int_easy(to_print, nb, size);
	(*to_print)[size - 1] = '\0';
}

int	size_int(t_print param, char *nb_itoa)
{
	int		max1;
	int		max2;

	max1 = ft_max(param.field, param.precision + (nb_itoa[0] == '-'));
	max2 = ft_max(max1, ft_strlen(nb_itoa));
	return (max2 + 1);
}
