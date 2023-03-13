/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/13 20:18:46 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

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
	// draw_button(c);
	// if (c->menu == TRUE)
	// {
	// 	mlx_set_font(c->mlx.ptr, c->mlx.win.ptr, "10x20");
	// 	mlx_string_put(c->mlx.ptr, c->mlx.win.ptr, 486, 64, 0x0FFFF00, "CUB3D MENU");
	// 	c->menu = FALSE;
	// }
	return (0);
}
