/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:43:04 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/29 12:15:19 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	door_wall_too_close(t_data *door, double new[2], char c)
{
	if (c == 'W')
	{
		if (door->map.grid[(int)(door->ray.pos[Y]
				+ door->ray.dir[Y] * 0.2)][(int)new[X]] == '1' ||
				door->map.grid[(int)
				(door->ray.pos[Y]
				+ door->ray.dir[Y] * 0.2)][(int)new[X]] == 'D')
			return (1);
		if (door->map.grid[(int)(door->ray.pos[Y]
				+ door->ray.dir[X] * 0.2)][(int)new[X]] == '1'
				|| door->map.grid[(int)(door->ray.pos[Y]
				+ door->ray.dir[X] * 0.2)][(int)new[X]] == 'D')
			return (1);
	}
	if (c == 'S')
	{
		if (door->map.grid[(int)(door->ray.pos[Y]
				+ door->ray.dir[Y] * 0.2)][(int)new[X]] == '1'
				|| door->map.grid[(int)(door->ray.pos[Y]
				+ door->ray.dir[Y] * 0.2)][(int)new[X]] == 'D')
			return (1);
		if (door->map.grid[(int)(door->ray.pos[Y]
				+ door->ray.dir[X] * 0.2)][(int)new[X]] == '1'
				|| door->map.grid[(int)(door->ray.pos[Y]
				+ door->ray.dir[X] * 0.2)][(int)new[X]] == 'D')
			return (1);
	}
	return (door_wall_too_close2(door, c));
}

int	door_wall_too_close2(t_data *door, char c)
{
	if (c == 'A')
	{
		if (door->map.grid[(int)(door->ray.pos[Y])][(int)(door->ray.pos[X]
			+ door->ray.dir[Y] * 0.2)] == '1'
			|| door->map.grid[(int)(door->ray.pos[Y])]
				[(int)(door->ray.pos[X] + door->ray.dir[Y] * 0.2)] == 'D')
			return (1);
		if (door->map.grid[(int)(door->ray.pos[Y] - door->ray.dir[X] * 0.2)]
			[(int)(door->ray.pos[X])] == '1'
			|| door->map.grid[(int)(door->ray.pos[Y]
				- door->ray.dir[X] * 0.2)][(int)(door->ray.pos[X])] == 'D')
			return (1);
	}
	if (c == 'D')
	{
		if (door->map.grid[(int)(door->ray.pos[Y])][(int)(door->ray.pos[X]
			+ door->ray.dir[Y] * 0.2)] == '1'
			|| door->map.grid[(int)(door->ray.pos[Y])]
				[(int)(door->ray.pos[X] + door->ray.dir[Y] * 0.2)] == 'D')
			return (1);
		if (door->map.grid[(int)(door->ray.pos[Y] - door->ray.dir[X] * 0.2)]
			[(int)(door->ray.pos[X])] == '1'
			|| door->map.grid[(int)(door->ray.pos[Y]
				- door->ray.dir[X] * 0.2)][(int)(door->ray.pos[X])] == 'D')
			return (1);
	}
	return (0);
}

void	ray_collision(t_ray *ray, t_map *map)
{
	float	dist;

	if (map->grid[ray->map[Y]][ray->map[X]] == '1')
			ray->hit = 1;
	else if (map->grid[ray->map[Y]][ray->map[X]] == 'P' && ray->click == 1)
	{
		map->grid[ray->map[Y]][ray->map[X]] = 'D';
		ray->click = 0;
		ray->hit = 1;
	}
	else if (map->grid[ray->map[Y]][ray->map[X]] == 'D')
	{
		dist = (ray->ray_side[X] - ray->delta[X]);
		if (ray->click == 1 && dist < 0.8)
		{
			map->grid[ray->map[Y]][ray->map[X]] = 'P';
			ray->click = 0;
		}
		else
		{
			ray->hit = 1;
			ray->door = 1;
		}
	}
}
