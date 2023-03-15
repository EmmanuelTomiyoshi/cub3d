/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:10:21 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/15 12:38:00 by etomiyos         ###   ########.fr       */
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

int	draw(t_cub3d *c)
{
	if (c->menu.active && c->menu.fullscreen.toggle == FALSE)
	{
		draw_button(c->menu.fullscreen, c);
		mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->menu.img.ptr, 0, 0);
	}
	else
	{
		background(c);
		movements(c);
		camera(c);
		pixel(c);
		mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->mlx.img.ptr, 0, 0);
	}
	return (0);
}
