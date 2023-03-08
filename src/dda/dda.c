/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/08 20:28:17 by etomiyos         ###   ########.fr       */
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
	double		dda_linesize_x;
	double		dda_linesize_y;
	t_vector	wall_map_pos;

	wall_map_pos.x = floor((double)c->player.pos.x);
	wall_map_pos.y = floor((double)c->player.pos.y);
	hit = FALSE;
	dda_linesize_x = c->dist.to_side.x;
	dda_linesize_y = c->dist.to_side.y;
	while (hit == FALSE)
	{
		if (dda_linesize_x < dda_linesize_y)
		{
			wall_map_pos.x += c->dist.step.x;
			dda_linesize_x += c->dist.delta.x;
		}
		else
		{
			wall_map_pos.y += c->dist.step.y;
			dda_linesize_y += c->dist.delta.y;
		}
		if (c->map.map[(int)wall_map_pos.x][(int)wall_map_pos.y] == '1')
			hit = TRUE;
	}
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
