/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:57:01 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 18:53:55 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_map *map, int x, int y)
{
	if (map->map[x][y] == 'N')
	{
		rotate_vector(&map->player.dir, 270);
		rotate_vector(&map->player.camera.plane, 270);
	}
	if (map->map[x][y] == 'E')
	{
		rotate_vector(&map->player.dir, 180);
		rotate_vector(&map->player.camera.plane, 180);
	}
	if (map->map[x][y] == 'S')
	{
		rotate_vector(&map->player.dir, 90);
		rotate_vector(&map->player.camera.plane, 90);
	}
	if (map->map[x][y] == 'W')
	{
		rotate_vector(&map->player.dir, 0.01);
		rotate_vector(&map->player.camera.plane, 0.01);
	}
}

void	get_player_data(t_map *map, t_cub3d *c, int x, int y)
{
	verify_surrounding(map, c, x, y);
	map->player.pos.x = x + 0.5;
	map->player.pos.y = y + 0.5;
	map->player.dir.x = 0;
	map->player.dir.y = -1;
	map->player.camera.plane.x = 0.66;
	map->player.camera.plane.y = 0;
	map->player.camera.pixel.x = 0;
	map->player.camera.pixel.y = 0;
	rotate_player(map, x, y);
	map->map[x][y] = '8';
}
