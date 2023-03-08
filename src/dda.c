/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/08 15:58:40 by mtomomit         ###   ########.fr       */
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

void	dda(t_cub3d *c, t_dist *dist, t_vector *raydir)
{
	t_bool		hit;
	double		ddaLineSizeX;
	double		ddaLineSizeY;
	t_vector	wallMapPos;

	(void)raydir;
	wallMapPos.x = floor(c->player.pos.x);
	wallMapPos.y = floor(c->player.pos.y);
	hit = FALSE;
	ddaLineSizeX = dist->to_side.x;
	ddaLineSizeY = dist->to_side.y;
	while (hit == FALSE)
	{
		if (ddaLineSizeX < ddaLineSizeY)
		{
			wallMapPos.x += dist->step.x;
			ddaLineSizeX += dist->delta.x;
		}
		else
		{
			wallMapPos.y += dist->step.y;
			ddaLineSizeY += dist->delta.y;
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

void	init_dist(t_cub3d *c, t_dist *dist, t_vector *raydir)
{
	t_vector	map_pos;

	dist->delta.x = fabs(1 / raydir->x);
	dist->delta.y = fabs(1 / raydir->y);
	map_pos.x = floor(c->player.pos.x);
	map_pos.y = floor(c->player.pos.y);
	if (raydir->x < 0)
		dist->to_side.x = (c->player.pos.x - map_pos.x) * dist->delta.x;
	else
		dist->to_side.x = (map_pos.x + 1 - c->player.pos.x) * dist->delta.x;
	if (raydir->y < 0)
		dist->to_side.y = (c->player.pos.y - map_pos.y) * dist->delta.y;
	else
		dist->to_side.y = (map_pos.y + 1 - c->player.pos.y) * dist->delta.y;
}

int	draw(t_cub3d *c)
{
	int			pixel;
	double		multiplier;
	t_dist		dist;

	pixel = 0;
	background(c);
	while (pixel <= WIDTH)
	{
		multiplier = 2 * (pixel / WIDTH) - 1;
		c->player.camera.pixel.x = c->player.camera.plane.x * multiplier;
		c->player.camera.pixel.y = c->player.camera.plane.y * multiplier;
		dist.raydir.x = c->player.camera.pixel.x + c->player.dir.x;
		dist.raydir.y = c->player.camera.pixel.y + c->player.dir.y;
		init_dist(c, &dist, &dist.raydir);
		pixel++;
	}
	mlx_put_image_to_window(c->mlx.ptr, c->mlx.win, c->mlx.img.image, 0, 0);
	return (0);
}
