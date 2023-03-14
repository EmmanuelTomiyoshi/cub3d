/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/14 15:36:27 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	background(t_cub3d *c)
{
	t_vector	point1;
	t_vector	point2;

	point1.x = 0;
	point1.y = 0;
	point2.x = (double) c->mlx.win.width;
	point2.y = 0;
	while (point1.y <= (double) c->mlx.win.height)
	{
		if (point1.y <= (double) c->mlx.win.height / 2)
			bresenham(&point1, &point2, c, c->map.c_color);
		else
			bresenham(&point1, &point2, c, c->map.f_color);
		point1.y++;
		point2.y++;
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

void	draw_texture(t_cub3d *c, int pixel, int wall_line_height)
{
	char	*dst;
	int	draw_start = -wall_line_height / 2 + c->mlx.win.height / 2;
	if (draw_start < 0)
		draw_start = 0;
	int draw_end = wall_line_height / 2 + c->mlx.win.height / 2;
	if (draw_end >= c->mlx.win.height)
		draw_end = c->mlx.win.height - 1;
	double wallX;
	if (c->dda.hit.side == 0)
		wallX = c->player.pos.y + c->dda.perpendicular + c->dda.raydir.y;
	else
		wallX = c->player.pos.x + c->dda.perpendicular + c->dda.raydir.x;
	wallX -= floor((wallX));
	int texX = (int)(wallX * (double)c->mlx.ea_tex.width);
	if (c->dda.hit.side == 0 && c->dda.raydir.x > 0)
		texX = c->mlx.ea_tex.width - texX - 1;
	if (c->dda.hit.side == 1 && c->dda.raydir.y < 0)
		texX = c->mlx.ea_tex.width - texX - 1;
	double step = 1 * (double)c->mlx.ea_tex.height / wall_line_height;
	double texPos = (draw_start - c->mlx.win.height / 2 + wall_line_height / 2) * step;
	for (int y = draw_start; y < draw_end; y++)
	{
		int texY = (int)texPos & ((int)c->mlx.ea_tex.height - 1);
		texPos += step;
		unsigned int color = *(unsigned int *)(c->mlx.ea_tex.img.addr + (texY * c->mlx.ea_tex.img.line_length + texX
				* (c->mlx.ea_tex.img.bits_per_pixel) / 8));
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + (c->mlx.win.width - pixel)
				* (c->mlx.img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
	}
}

void	raycasting(t_cub3d *c, int pixel)
{
	int			wall_line_height;
	//t_vector	point1;
	//t_vector	point2;

	wall_line_height = (int) (c->mlx.win.height / c->dda.perpendicular);
	draw_texture(c, pixel, wall_line_height);
	/*point1.x = c->mlx.win.width - (double) pixel;
	point1.y = (double) c->mlx.win.height / 2 - wall_line_height / 2;
	point2.x = c->mlx.win.width - (double)pixel;
	point2.y = (double) c->mlx.win.height / 2 + wall_line_height / 2;
	if (c->dda.hit.side == 0)
		bresenham(&point1, &point2, c, c->map.cube1);
	if (c->dda.hit.side == 1)
		bresenham(&point1, &point2, c, c->map.cube2);*/
}

void	movements(t_cub3d *c)
{
	if (c->player.look_left)
		look_left(c);
	if (c->player.look_right)
		look_right(c);
	if (c->player.move_backwards)
		walk_backward(c);
	if (c->player.move_foward)
		walk_forward(c);
	if (c->player.move_left)
		walk_left(c);
	if (c->player.move_right)
		walk_right(c);
}

int	draw(t_cub3d *c)
{
	background(c);
	movements(c);
	while (c->dda.pixel < c->mlx.win.width)
	{
		init_camera(c);
		init_raydir_and_delta(c);
		init_dist_to_side(c);
		dda(c);
		init_perpendicular(c);
		raycasting(c, c->dda.pixel);
		c->dda.pixel++;
	}
	c->dda.pixel = 0;
	mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->mlx.img.image, 0, 0);
	// if (c->menu == TRUE)
	// {
	// 	mlx_set_font(c->mlx.ptr, c->mlx.win.ptr, "10x20");
	// 	mlx_string_put(c->mlx.ptr, c->mlx.win.ptr, 486, 64, 0x0FFFF00, "CUB3D MENU");
	// 	c->menu = FALSE;
	// }
	return (0);
}
