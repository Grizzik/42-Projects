/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_rgb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:49 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/29 17:35:56 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb(t_data *game)
{
	char	**tab;
	int		tab_int[3];

	tab = ft_split(game->map.c_color, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	if (tab[0] && tab[2] && tab[1])
	{
		tab_int[0] = ft_atoi(tab[0]);
		tab_int[1] = ft_atoi(tab[1]);
		tab_int[2] = ft_atoi(tab[2]);
	}
	else
		return (free_tab(tab, 0), 1);
	game->map.c_color_int = algo_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	tab = ft_split(game->map.f_color, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	if (tab[0] && tab[2] && tab[1])
	{
		tab_int[0] = ft_atoi(tab[0]);
		tab_int[1] = ft_atoi(tab[1]);
		tab_int[2] = ft_atoi(tab[2]);
	}
	else
		return (free_tab(tab, 0), 1);
	game->map.f_color_int = algo_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	return (0);
}

int	check_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i][0] < '0' || tab[i][0] > '9')
			return (1);
		if (is_digit(tab[i]))
			return (1);
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (1);
		if (ft_strlen(tab[i]) > 3)
			return (1);
		if (ft_strlen(tab[i]) == 0)
			return (1);
		if (i > 3)
			return (1);
	}
	return (0);
}

int	algo_rgb(int r, int g, int b)
{
	return (r * 12500 + g * 256 + b);
}
