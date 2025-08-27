/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:15:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/29 19:09:00 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_free(void *address)
{
	if (address)
	{
		free(address);
		address = NULL;
	}
}

void	free_tab(char **tab, int n)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] && (i < n || n == 0))
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	free_img(t_data *data)
{
	if (data->alloc == 1)
	{
		ft_free(data->map.n_texture_path);
		ft_free(data->map.s_texture_path);
		ft_free(data->map.w_texture_path);
		ft_free(data->map.e_texture_path);
		ft_free(data->map.c_color);
		ft_free(data->map.f_color);
	}
}

void	free_map_lst(t_lst *lst_map)
{
	t_lst	*before;

	if (!lst_map)
		return ;
	before = lst_map;
	while (lst_map)
	{
		lst_map = lst_map->next;
		ft_free(before->mapline);
		ft_free(before);
		before = lst_map;
	}
}

void	free_all(t_data *game)
{
	free_img(game);
	free_tab(game->map.grid, 0);
	destroy_all(game);
}
