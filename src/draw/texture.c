/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:55:20 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 12:08:23 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_brightness(t_cub3d *c)
{
	if (c->light_mode == TRUE)
	{
		c->draw.color = blending(c->draw.color, ADD_LIGHT, c);
	}
}

unsigned int	return_color(t_image *img, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(img->addr + \
			(y * img->line_length + x * (img->bits_per_pixel) / 8));
	return (color);
}

static unsigned int	get_pixel_color(t_cub3d *c)
{
	unsigned int	color;

	if (c->dda.hit.side == 0)
	{
		if (c->dda.raydir.x < 0)
			color = return_color(&c->mlx.no_tex.img, \
				c->draw.tex_x, c->draw.tex_y);
		else
			color = return_color(&c->mlx.so_tex.img, \
				c->draw.tex_x, c->draw.tex_y);
	}
	else
	{
		if (c->dda.raydir.y < 0)
			color = return_color(&c->mlx.we_tex.img, \
				c->draw.tex_x, c->draw.tex_y);
		else
			color = return_color(&c->mlx.ea_tex.img, \
				c->draw.tex_x, c->draw.tex_y);
	}
	return (color);
}

static void	draw_pixel(t_cub3d *c, int pixel)
{
	char	*dst;
	int		y;

	y = c->draw.start;
	while (y < c->draw.end)
	{
		c->draw.tex_y = (int)c->draw.tex_pos & (c->mlx.ea_tex.height - 1);
		c->draw.tex_pos += c->draw.step;
		c->draw.color = get_pixel_color(c);
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + \
				(c->mlx.win.width - pixel) \
				* (c->mlx.img.bits_per_pixel) / 8);
		change_brightness(c);
		*(unsigned int *) dst = c->draw.color;
		y++;
	}
}

void	draw_texture(t_cub3d *c, int pixel)
{
	c->draw.wall_x -= floor((c->draw.wall_x));
	c->draw.tex_x = (double)(c->draw.wall_x * (double)c->mlx.ea_tex.width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		c->draw.tex_x = c->mlx.ea_tex.width - c->draw.tex_x - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		c->draw.tex_x = c->mlx.ea_tex.width - c->draw.tex_x - 1;
	c->draw.step = 1 * (double)c->mlx.ea_tex.height / c->draw.wall_line_height;
	c->draw.tex_pos = (c->draw.start - (double) c->mlx.win.height / 2 + \
		(double) c->draw.wall_line_height / 2) * c->draw.step;
	draw_pixel(c, pixel);
}
