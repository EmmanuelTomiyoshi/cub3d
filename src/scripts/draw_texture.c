/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:55:20 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/14 18:38:00 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture_ea(t_cub3d *c, int pixel, t_vector wall, t_vector draw)
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

void	draw_texture_so(t_cub3d *c, int pixel, t_vector wall, t_vector draw)
{
	char			*dst;
	t_vector		tex;
	t_vector		pos;
	unsigned int	color;
	int				y;

	tex.x = (double)(wall.x * (double)c->mlx.so_tex.width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		tex.x = c->mlx.so_tex.width - tex.x - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		tex.x = c->mlx.so_tex.width - tex.x - 1;
	pos.y = 1 * (double)c->mlx.so_tex.height / wall.y;
	pos.x = (draw.x - (double) c->mlx.win.height / 2 + (double) wall.y / 2) * pos.y;
	y = (int)draw.x;
	while(y < draw.y)
	{
		tex.y = (int)pos.x & ((int)c->mlx.so_tex.height - 1);
		pos.x += pos.y;
		color = *(unsigned int *)(c->mlx.so_tex.img.addr + ((int)tex.y * c->mlx.so_tex.img.line_length + (int)tex.x
				* (c->mlx.so_tex.img.bits_per_pixel) / 8));
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + (c->mlx.win.width - pixel)
				* (c->mlx.img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
		y++;
	}
}

void	draw_texture_no(t_cub3d *c, int pixel, t_vector wall, t_vector draw)
{
	char			*dst;
	t_vector		tex;
	t_vector		pos;
	unsigned int	color;
	int				y;

	tex.x = (double)(wall.x * (double)c->mlx.no_tex.width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		tex.x = c->mlx.no_tex.width - tex.x - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		tex.x = c->mlx.no_tex.width - tex.x - 1;
	pos.y = 1 * (double)c->mlx.no_tex.height / wall.y;
	pos.x = (draw.x - (double) c->mlx.win.height / 2 + (double) wall.y / 2) * pos.y;
	y = (int)draw.x;
	while(y < draw.y)
	{
		tex.y = (int)pos.x & ((int)c->mlx.no_tex.height - 1);
		pos.x += pos.y;
		color = *(unsigned int *)(c->mlx.no_tex.img.addr + ((int)tex.y * c->mlx.no_tex.img.line_length + (int)tex.x
				* (c->mlx.no_tex.img.bits_per_pixel) / 8));
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + (c->mlx.win.width - pixel)
				* (c->mlx.img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
		y++;
	}
}

void	draw_texture_we(t_cub3d *c, int pixel, t_vector wall, t_vector draw)
{
	char			*dst;
	t_vector		tex;
	t_vector		pos;
	unsigned int	color;
	int				y;

	tex.x = (double)(wall.x * (double)c->mlx.we_tex.width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		tex.x = c->mlx.we_tex.width - tex.x - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		tex.x = c->mlx.we_tex.width - tex.x - 1;
	pos.y = 1 * (double)c->mlx.we_tex.height / wall.y;
	pos.x = (draw.x - (double) c->mlx.win.height / 2 + (double) wall.y / 2) * pos.y;
	y = (int)draw.x;
	while(y < draw.y)
	{
		tex.y = (int)pos.x & ((int)c->mlx.we_tex.height - 1);
		pos.x += pos.y;
		color = *(unsigned int *)(c->mlx.we_tex.img.addr + ((int)tex.y * c->mlx.we_tex.img.line_length + (int)tex.x
				* (c->mlx.we_tex.img.bits_per_pixel) / 8));
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + (c->mlx.win.width - pixel)
				* (c->mlx.img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
		y++;
	}
}
