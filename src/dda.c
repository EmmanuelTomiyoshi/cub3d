/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/08 19:43:43 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	background(t_cub3d *c)
{
	t_point	point1;
	t_point	point2;

	point1.x = 0;
	point1.y = 0;
	point2.x = WIDTH;
	point2.y = 0;
	while (point1.y <= HEIGHT)
	{
		if (point1.y <= HEIGHT / 2)
			bresenham(&point1, &point2, c, c->map.c_color);
		else
			bresenham(&point1, &point2, c, c->map.f_color);
		point1.y++;
		point2.y++;
	}
}

void	dda(t_cub3d *c)
{
	t_bool		hit;
	double		ddaLineSizeX;
	double		ddaLineSizeY;
	t_vector	wallMapPos;

	wallMapPos.x = floor(c->player.pos.x);
	wallMapPos.y = floor(c->player.pos.y);
	hit = FALSE;
	ddaLineSizeX = c->dist.to_side.x;
	ddaLineSizeY = c->dist.to_side.y;
	while (hit == FALSE)
	{
		if (ddaLineSizeX < ddaLineSizeY)
		{
			wallMapPos.x += c->dist.step.x;
			ddaLineSizeX += c->dist.delta.x;
		}
		else
		{
			wallMapPos.y += c->dist.step.y;
			ddaLineSizeY += c->dist.delta.y;
		}
		if (c->map.map[(int)wallMapPos.x][(int)wallMapPos.y] == '1')
			hit = TRUE;
	}
}

void	init_stepXY(t_cub3d *c, t_dist *dist, t_vector *raydir)
{
	(void)c;
	if (raydir->x < 0)
		dist->step.x = -1;
	else
		dist->step.x = 1;
	if (raydir->y < 0)
		dist->step.y = -1;
	else
		dist->step.y = 1;
}

void	init_dist(t_cub3d *c)
{
	t_vector	map_pos;

	c->dist.delta.x = fabs(1 / c->dist.raydir.x);
	c->dist.delta.y = fabs(1 / c->dist.raydir.y);
	map_pos.x = floor(c->player.pos.x);
	map_pos.y = floor(c->player.pos.y);
	if (c->dist.raydir.x < 0)
		c->dist.to_side.x = (c->player.pos.x - map_pos.x) * c->dist.delta.x;
	else
		c->dist.to_side.x = (map_pos.x + 1 - c->player.pos.x) * c->dist.delta.x;
	if (c->dist.raydir.y < 0)
		c->dist.to_side.y = (c->player.pos.y - map_pos.y) * c->dist.delta.y;
	else
		c->dist.to_side.y = (map_pos.y + 1 - c->player.pos.y) * c->dist.delta.y;
}

void	init_camera(t_cub3d *c)
{
	double	multiplier;

	multiplier = 2 * (c->dist.pixel / WIDTH) - 1;
	c->player.camera.pixel.x = c->player.camera.plane.x * multiplier;
	c->player.camera.pixel.y = c->player.camera.plane.y * multiplier;
}

void	init_raydir(t_cub3d *c)
{
	c->dist.raydir.x = c->player.camera.pixel.x + c->player.dir.x;
	c->dist.raydir.y = c->player.camera.pixel.y + c->player.dir.y;
}

int	draw(t_cub3d *c)
{
	background(c);
	while (c->dist.pixel <= WIDTH)
	{
		init_camera(c);
		init_raydir(c);
		init_dist(c);
		c->dist.pixel++;
	}
	mlx_put_image_to_window(c->mlx.ptr, c->mlx.win, c->mlx.img.image, 0, 0);
	return (0);
}
