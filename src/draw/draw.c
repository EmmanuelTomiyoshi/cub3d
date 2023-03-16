/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:10:21 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/16 16:37:35 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	background(t_cub3d *c)
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

void	pixel(t_cub3d *c)
{
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
}

// void	crosshair(t_cub3d *c)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < 8)
// 	{
// 		y = 0;
// 		while (y < 64)
// 		{
// 			my_pixel_put(&c->mlx.img, (x - 16) + c->mlx.win.width / 2,
// 					(y - 32) + c->mlx.win.height / 2, DARK_BLUE);
// 			y++;
// 		}
// 		x++;
// 	}
// }


int	draw(t_cub3d *c)
{
	if (c->menu.active)
	{
		if (c->menu.fullscreen.toggle)
		{
			get_btn_pos(&c->menu.quit, (int)(BTN_X * c->menu.width_ratio), (int)(BTN_Y * c->menu.height_ratio));
			get_btn_size(&c->menu.quit, (int)(BTN_WIDTH * c->menu.width_ratio), (int)(BTN_HEIGHT * c->menu.height_ratio));
			mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->menu.resize.ptr, 0, 0);
		}
		else
		{
			get_btn_pos(&c->menu.quit, BTN_X, BTN_Y);
			get_btn_size(&c->menu.quit, BTN_WIDTH, BTN_HEIGHT);
			mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->menu.img.ptr, 0, 0);
		}
	}
	else
	{
		background(c);
		movements(c);
		camera(c);
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
		draw_minimap(c);
		pixel(c);
		// crosshair(c);
		animate_sprite(c);
		mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->mlx.img.ptr, 0, 0);
	}
	return (0);
}
