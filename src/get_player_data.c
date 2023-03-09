/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:57:01 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/09 17:35:42 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_data(t_cub3d *c, int x, int y)
{
	verify_surrounding(c, NULL, x, y);
	c->map.map[x][y] = '8';
	c->player.pos.x = x + 0.45;
	c->player.pos.y = y + 0.5;
	c->player.dir.x = 0;
	c->player.dir.y = -1;
	c->player.camera.plane.x = 0.66;
	c->player.camera.plane.y = 0;
	c->player.camera.pixel.x = 0;
	c->player.camera.pixel.y = 0;
}
