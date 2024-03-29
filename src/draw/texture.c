/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:55:20 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 11:33:14 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	return_color(t_image *img, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(img->addr + \
			(y * img->line_length + x * (img->bits_per_pixel) / 8));
	return (color);
}

static unsigned int	get_pixel_color(t_cub3d *c, t_texture *tex)
{
	unsigned int	color;

	color = return_color(&tex->img, c->draw.tex_x, c->draw.tex_y);
	return (color);
}

static void	draw_pixel(t_cub3d *c, int pixel, t_texture *tex)
{
	char	*dst;
	int		y;

	y = c->draw.start;
	while (y < c->draw.end)
	{
		c->draw.tex_y = (int)c->draw.tex_pos & (c->map.ea_tex.height - 1);
		c->draw.tex_pos += c->draw.step;
		c->draw.color = get_pixel_color(c, tex);
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + \
				(c->mlx.win.width - pixel) \
				* (c->mlx.img.bits_per_pixel) / 8);
		change_brightness(c);
		*(unsigned int *) dst = c->draw.color;
		y++;
	}
}

static void	check_distortion(t_cub3d *c)
{
	if (c->state.distortion == TRUE)
	{
		if (c->dda.hit.side == 0)
			c->draw.wall_x = c->map.player.pos.y + c->dda.perpendicular
				+ c->dda.raydir.y;
		else
			c->draw.wall_x = c->map.player.pos.x + c->dda.perpendicular
				+ c->dda.raydir.x;
	}
	else
	{
		if (c->dda.hit.side == 0)
			c->draw.wall_x = c->map.player.pos.y + c->dda.perpendicular
				* c->dda.raydir.y;
		else
			c->draw.wall_x = c->map.player.pos.x + c->dda.perpendicular
				* c->dda.raydir.x;
	}
}

void	draw_texture(t_cub3d *c, int pixel, t_texture *tex)
{
	check_distortion(c);
	c->draw.wall_x -= floor((c->draw.wall_x));
	c->draw.tex_x = (double)(c->draw.wall_x * (double)tex->width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		c->draw.tex_x = tex->width - c->draw.tex_x - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		c->draw.tex_x = tex->width - c->draw.tex_x - 1;
	c->draw.step = 1 * (double)tex->height / c->draw.wall_line_height;
	c->draw.tex_pos = (c->draw.start - (double) c->mlx.win.height / 2 + \
		(double) c->draw.wall_line_height / 2) * c->draw.step;
	draw_pixel(c, pixel, tex);
}
