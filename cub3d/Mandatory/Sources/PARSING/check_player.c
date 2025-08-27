/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:46:39 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/29 19:09:40 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	dir_player(t_data *game, char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player++;
				set_value(game, map[i][j], i, j);
				game->map.grid[i][j] = '0';
			}
		}
	}
	return (return_dir_player(player));
}

int	return_dir_player(int player)
{
	if (player < 1)
		return (msg_error(NO_PLAYER, NULL, 1));
	else if (player > 1)
		return (msg_error(TOO_PLAYER, NULL, 1));
	return (0);
}
