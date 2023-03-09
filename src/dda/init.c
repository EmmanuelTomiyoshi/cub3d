/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:22:41 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/09 10:07:01 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_step_xy(t_cub3d *c, t_dist *dist, t_vector *raydir)
{
	if (raydir->x < 0)
		dist->step.x = -1;
	else
		dist->step.x = 1;
	if (raydir->y < 0)
		dist->step.y = -1;
	else
		dist->step.y = 1;
}

void	init_dist(t_cub3d *c)
{
	t_vector	map_pos;

	c->dist.delta.x = fabs(1 / c->dist.raydir.x);
	c->dist.delta.y = fabs(1 / c->dist.raydir.y);
	map_pos.x = floor(c->player.pos.x);
	map_pos.y = floor(c->player.pos.y);
	if (c->dist.raydir.x < 0)
		c->dist.to_side.x = (c->player.pos.x - map_pos.x) * c->dist.delta.x;
	else
		c->dist.to_side.x = (map_pos.x + 1 - c->player.pos.x) * c->dist.delta.x;
	if (c->dist.raydir.y < 0)
		c->dist.to_side.y = (c->player.pos.y - map_pos.y) * c->dist.delta.y;
	else
		c->dist.to_side.y = (map_pos.y + 1 - c->player.pos.y) * c->dist.delta.y;
}

void	init_camera(t_cub3d *c)
{
	double	multiplier;

	multiplier = 2 * (c->dist.pixel / WIDTH) - 1;
	c->player.camera.pixel.x = c->player.camera.plane.x * multiplier;
	c->player.camera.pixel.y = c->player.camera.plane.y * multiplier;
}

void	init_raydir(t_cub3d *c)
{
	c->dist.raydir.x = c->player.camera.pixel.x + c->player.dir.x;
	c->dist.raydir.y = c->player.camera.pixel.y + c->player.dir.y;
}
