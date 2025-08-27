/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:37:33 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/29 19:20:45 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cam_mouse(int x, int y, t_data *game)
{
	double	move;

	(void)y;
	if (game->m_moves_struc == 10000)
	{
		game->m_moves_struc = x;
		return (0);
	}
	move = (game->m_moves_struc - x) * 0.01;
	move_cam(game, -move);
	game->m_moves_struc = x;
	return (0);
}

int	mouse_clic(int clic, int y, int x, t_data *data)
{
	(void)y;
	(void)x;
	if (clic == 1)
		data->ray.click = 1;
	return (0);
}
