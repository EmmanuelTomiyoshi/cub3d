/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/14 15:55:57 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_cub3d *c)
{
	c->dda.wall_pos.x = floor((double)c->player.pos.x);
	c->dda.wall_pos.y = floor((double)c->player.pos.y);
	c->dda.hit.hit = FALSE;
	c->dda.line_size.x = c->dda.to_side.x;
	c->dda.line_size.y = c->dda.to_side.y;
	while (c->dda.hit.hit == FALSE)
	{
		if (c->dda.line_size.x < c->dda.line_size.y)
		{
			c->dda.wall_pos.x += c->dda.step.x;
			c->dda.line_size.x += c->dda.delta.x;
			c->dda.hit.side = 0;
		}
		else
		{
			c->dda.wall_pos.y += c->dda.step.y;
			c->dda.line_size.y += c->dda.delta.y;
			c->dda.hit.side = 1;
		}
		if (c->map.map[(int)c->dda.wall_pos.x][(int)c->dda.wall_pos.y] == '1')
			c->dda.hit.hit = TRUE;
	}
}

void	raycasting(t_cub3d *c, int pixel)
{
	double		wall_line_height;
	t_vector	point1;
	t_vector	point2;

	wall_line_height = (double) c->mlx.win.height / c->dda.perpendicular;
	point1.x = c->mlx.win.width - (double) pixel;
	point1.y = (double) c->mlx.win.height / 2 - wall_line_height / 2;
	point2.x = c->mlx.win.width - (double)pixel;
	point2.y = (double) c->mlx.win.height / 2 + wall_line_height / 2;
	if (c->dda.hit.side == 0)
		bresenham(&point1, &point2, c, c->map.cube1);
	if (c->dda.hit.side == 1)
		bresenham(&point1, &point2, c, c->map.cube2);
}
