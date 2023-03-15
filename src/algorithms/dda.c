/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/15 11:59:50 by mtomomit         ###   ########.fr       */
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
	t_draw	draw;

	draw = (t_draw){0};
	draw.wall_line_height = (int) c->mlx.win.height / c->dda.perpendicular;
	draw.start = -draw.wall_line_height / 2 + (double) c->mlx.win.height / 2;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = draw.wall_line_height / 2 + (double) c->mlx.win.height / 2;
	if (draw.end >= c->mlx.win.height)
		draw.end = c->mlx.win.height - 1;
	draw_texture(c, pixel, &draw);
}
