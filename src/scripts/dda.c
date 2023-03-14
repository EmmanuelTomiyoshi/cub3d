/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/14 18:38:03 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture(t_cub3d *c, int pixel, t_vector wall, t_vector draw)
{
	char			*dst;
	t_vector		tex;
	t_vector		pos;
	unsigned int	color;
	int				y;

	tex.x = (double)(wall.x * (double)c->mlx.ea_tex.width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		tex.x = c->mlx.ea_tex.width - tex.x - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		tex.x = c->mlx.ea_tex.width - tex.x - 1;
	pos.y = 1 * (double)c->mlx.ea_tex.height / wall.y;
	pos.x = (draw.x - (double) c->mlx.win.height / 2 + (double) wall.y / 2) * pos.y;
	y = (int)draw.x;
	while(y < draw.y)
	{
		tex.y = (int)pos.x & ((int)c->mlx.ea_tex.height - 1);
		pos.x += pos.y;
		color = *(unsigned int *)(c->mlx.ea_tex.img.addr + ((int)tex.y * c->mlx.ea_tex.img.line_length + (int)tex.x
				* (c->mlx.ea_tex.img.bits_per_pixel) / 8));
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + (c->mlx.win.width - pixel)
				* (c->mlx.img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
		y++;
	}
}

void	verify_wall(t_cub3d *c, int pixel, t_vector wall, t_vector draw)
{
	if (c->dda.hit.side == 0)
	{
		wall.x = c->player.pos.y + c->dda.perpendicular + c->dda.raydir.y;
		wall.x -= floor((wall.x));
		if (c->dda.raydir.x < 0)
			draw_texture_so(c, pixel, wall, draw);
		else
			draw_texture_no(c, pixel, wall, draw);
	}
	else
	{
		wall.x = c->player.pos.x + c->dda.perpendicular + c->dda.raydir.x;
		wall.x -= floor((wall.x));
		if (c->dda.raydir.y < 0)
			draw_texture_we(c, pixel, wall, draw);
		else
			draw_texture_ea(c, pixel, wall, draw);
	}
}

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
	t_vector	wall;
	t_vector	draw;

	wall.y = (int) (c->mlx.win.height / c->dda.perpendicular);
	draw.x = -wall.y / 2 + c->mlx.win.height / 2;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = wall.y / 2 + c->mlx.win.height / 2;
	if (draw.y >= c->mlx.win.height)
		draw.y = c->mlx.win.height - 1;
	verify_wall(c, pixel, wall, draw);
}
