/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:22:41 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 15:56:09 by mtomomit         ###   ########.fr       */
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

	map_pos.x = floor(c->player.pos.x);
	map_pos.y = floor(c->player.pos.y);
	if (c->dda.raydir.x < 0)
		c->dda.to_side.x = (c->player.pos.x - map_pos.x) * c->dda.delta.x;
	else
		c->dda.to_side.x = (map_pos.x + 1 - c->player.pos.x) * c->dda.delta.x;
	if (c->dda.raydir.y < 0)
		c->dda.to_side.y = (c->player.pos.y - map_pos.y) * c->dda.delta.y;
	else
		c->dda.to_side.y = (map_pos.y + 1 - c->player.pos.y) * c->dda.delta.y;
	init_step_xy(c);
}

void	init_camera(t_cub3d *c)
{
	double	multiplier;

	multiplier = 2 * ((double)c->dda.pixel / (double) c->mlx.win.width) - 1;
	c->player.camera.pixel.x = c->player.camera.plane.x * multiplier;
	c->player.camera.pixel.y = c->player.camera.plane.y * multiplier;
}

void	init_raydir_and_delta(t_cub3d *c)
{
	c->dda.raydir.x = c->player.camera.pixel.x + c->player.dir.x;
	c->dda.raydir.y = c->player.camera.pixel.y + c->player.dir.y;
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
		c->dda.perpendicular = fabs(c->dda.wall_pos.x - c->player.pos.x \
		+ ((1 - c->dda.step.x) / 2)) / c->dda.raydir.x;
	else
		c->dda.perpendicular = fabs(c->dda.wall_pos.y - c->player.pos.y \
		+ ((1 - c->dda.step.y) / 2)) / c->dda.raydir.y;
}
