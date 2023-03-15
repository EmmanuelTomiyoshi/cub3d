/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:55:20 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/15 12:17:03 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	return_color(t_image *img, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(img->addr + \
			(y * img->line_length + x * (img->bits_per_pixel) / 8));
	return (color);
}

static unsigned int	get_pixel_color(t_cub3d *c, t_draw *draw)
{
	unsigned int	color;

	if (c->dda.hit.side == 0)
	{
		if (c->dda.raydir.x < 0)
			color = return_color(&c->mlx.no_tex.img, draw->tex_x, draw->tex_y);
		else
			color = return_color(&c->mlx.so_tex.img, draw->tex_x, draw->tex_y);
	}
	else
	{
		if (c->dda.raydir.y < 0)
			color = return_color(&c->mlx.we_tex.img, draw->tex_x, draw->tex_y);
		else
			color = return_color(&c->mlx.ea_tex.img, draw->tex_x, draw->tex_y);
	}
	return (color);
}

static void	draw_pixel(t_cub3d *c, int pixel, t_draw *draw)
{
	char			*dst;
	unsigned int	color;
	int				y;

	y = draw->start;
	while (y < draw->end)
	{
		draw->tex_y = (int)draw->tex_pos & (c->mlx.ea_tex.height - 1);
		draw->tex_pos += draw->step;
		color = get_pixel_color(c, draw);
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + \
				(c->mlx.win.width - pixel) \
				* (c->mlx.img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
		y++;
	}
}

void	draw_texture(t_cub3d *c, int pixel, t_draw *draw)
{
	if (c->dda.hit.side == 0)
		draw->wall_x = c->player.pos.y + c->dda.perpendicular * c->dda.raydir.y;
	else
		draw->wall_x = c->player.pos.x + c->dda.perpendicular * c->dda.raydir.x;
	draw->wall_x -= floor((draw->wall_x));
	draw->tex_x = (double)(draw->wall_x * (double)c->mlx.ea_tex.width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		draw->tex_x = c->mlx.ea_tex.width - draw->tex_x - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		draw->tex_x = c->mlx.ea_tex.width - draw->tex_x - 1;
	draw->step = 1 * (double)c->mlx.ea_tex.height / draw->wall_line_height;
	draw->tex_pos = (draw->start - (double) c->mlx.win.height / 2 + \
		(double) draw->wall_line_height / 2) * draw->step;
	draw_pixel(c, pixel, draw);
}
