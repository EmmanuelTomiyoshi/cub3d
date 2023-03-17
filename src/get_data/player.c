/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:57:01 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 12:27:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_map *map, t_cub3d *c, int x, int y)
{
	if (map->map[x][y] == 'N')
	{
		rotate_vector(&c->player.dir, 270);
		rotate_vector(&c->player.camera.plane, 270);
	}
	if (map->map[x][y] == 'E')
	{
		rotate_vector(&c->player.dir, 180);
		rotate_vector(&c->player.camera.plane, 180);
	}
	if (map->map[x][y] == 'S')
	{
		rotate_vector(&c->player.dir, 90);
		rotate_vector(&c->player.camera.plane, 90);
	}
	if (map->map[x][y] == 'W')
	{
		rotate_vector(&c->player.dir, 0.01);
		rotate_vector(&c->player.camera.plane, 0.01);
	}
}

void	get_player_data(t_map *map, t_cub3d *c, int x, int y)
{
	verify_surrounding(map, c, NULL, x, y);
	c->player.pos.x = x + 0.5;
	c->player.pos.y = y + 0.5;
	c->player.dir.x = 0;
	c->player.dir.y = -1;
	c->player.camera.plane.x = 0.66;
	c->player.camera.plane.y = 0;
	c->player.camera.pixel.x = 0;
	c->player.camera.pixel.y = 0;
	c->player.look_left = FALSE;
	c->player.look_right = FALSE;
	c->player.move_foward = FALSE;
	c->player.move_backwards = FALSE;
	c->player.move_left = FALSE;
	c->player.move_right = FALSE;
	c->player.run = FALSE;
	rotate_player(map, c, x, y);
	map->map[x][y] = '8';
}
