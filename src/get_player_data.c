/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:57:01 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/10 08:47:30 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub3d *c, int x, int y)
{
	if (c->map.map[x][y] == 'N')
	{
		rotate_vector(&c->player.dir, 270);
		rotate_vector(&c->player.camera.plane, 270);
	}
	if (c->map.map[x][y] == 'E')
	{
		rotate_vector(&c->player.dir, 180);
		rotate_vector(&c->player.camera.plane, 180);
	}
	if (c->map.map[x][y] == 'S')
	{
		rotate_vector(&c->player.dir, 90);
		rotate_vector(&c->player.camera.plane, 90);
	}
}

void	get_player_data(t_cub3d *c, int x, int y)
{
	verify_surrounding(c, NULL, x, y);
	c->player.pos.x = x + 0.5;
	c->player.pos.y = y + 0.5;
	c->player.dir.x = 0;
	c->player.dir.y = -1;
	c->player.camera.plane.x = 0.66;
	c->player.camera.plane.y = 0;
	c->player.camera.pixel.x = 0;
	c->player.camera.pixel.y = 0;
	rotate_player(c, x, y);
	c->map.map[x][y] = '8';
}
