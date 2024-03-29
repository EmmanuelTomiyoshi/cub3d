/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:22:41 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/18 14:27:18 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_step_xy(t_cub3d *c)
{
	if (c->dda.raydir.x < 0)
		c->dda.step.x = -1;
	else
		c->dda.step.x = 1;
	if (c->dda.raydir.y < 0)
		c->dda.step.y = -1;
	else
		c->dda.step.y = 1;
}

void	init_dist_to_side(t_cub3d *c)
{
	t_vector	map_pos;

	map_pos.x = floor(c->map.player.pos.x);
	map_pos.y = floor(c->map.player.pos.y);
	if (c->dda.raydir.x < 0)
		c->dda.to_side.x = (c->map.player.pos.x - map_pos.x) * c->dda.delta.x;
	else
		c->dda.to_side.x = (map_pos.x + 1 - c->map.player.pos.x)
			* c->dda.delta.x;
	if (c->dda.raydir.y < 0)
		c->dda.to_side.y = (c->map.player.pos.y - map_pos.y)
			* c->dda.delta.y;
	else
		c->dda.to_side.y = (map_pos.y + 1 - c->map.player.pos.y)
			* c->dda.delta.y;
	init_step_xy(c);
}

void	init_camera(t_map *map, t_cub3d *c)
{
	double	multiplier;

	multiplier = 2 * ((double)c->dda.pixel / (double) c->mlx.win.width) - 1;
	map->player.camera.pixel.x = map->player.camera.plane.x * multiplier;
	map->player.camera.pixel.y = map->player.camera.plane.y * multiplier;
}

void	init_raydir_and_delta(t_cub3d *c)
{
	c->dda.raydir.x = c->map.player.camera.pixel.x + c->map.player.dir.x;
	c->dda.raydir.y = c->map.player.camera.pixel.y + c->map.player.dir.y;
	if (c->dda.raydir.x == 0)
	{
		c->dda.delta.x = 1;
		c->dda.delta.y = 0;
	}
	if (c->dda.raydir.y == 0)
	{
		c->dda.delta.x = 0;
		c->dda.delta.y = 1;
	}
	if (c->dda.raydir.y != 0 && c->dda.raydir.x != 0)
	{
		c->dda.delta.x = fabs(1 / c->dda.raydir.x);
		c->dda.delta.y = fabs(1 / c->dda.raydir.y);
	}
}

void	init_perpendicular(t_cub3d *c)
{
	if (c->dda.hit.side == 0)
		c->dda.perpendicular = c->dda.line_size.x - c->dda.delta.x;
	else
		c->dda.perpendicular = c->dda.line_size.y - c->dda.delta.y;
	if (c->state.distortion == TRUE)
	{
		if (c->dda.hit.side == 0)
			c->draw.wall_x = c->map.player.pos.y + c->dda.perpendicular + \
					c->dda.raydir.y;
		else
			c->draw.wall_x = c->map.player.pos.x + c->dda.perpendicular + \
				c->dda.raydir.x;
	}
	else
	{
		if (c->dda.hit.side == 0)
			c->draw.wall_x = c->map.player.pos.y + c->dda.perpendicular * \
				c->dda.raydir.y;
		else
			c->draw.wall_x = c->map.player.pos.x + c->dda.perpendicular * \
				c->dda.raydir.x;
	}
}
