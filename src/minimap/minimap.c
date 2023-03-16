/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:17:25 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/16 18:50:17 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_player(t_cub3d *c, int width, int height)
{
	t_vector	point2;
	t_vector	point;
	int			y;

	point.x = 96;
	point.y = 86;
	point2.x = point.x + width;
	point2.y = point.y;
	y = 0;
	while (y != height)
	{
		bresenham(&point, &point2, c, 16711680);
		point.y++;
		point2.y++;
		y++;
	}
}

static void	draw_white_rect(t_cub3d *c, int width, int height, t_vector point)
{
	t_vector	point2;
	int			y;

	point2.x = point.x + width;
	point2.y = point.y;
	y = 0;
	while (y != height)
	{
		if (c->map.c_color != 16777215)
			bresenham(&point, &point2, c, 16777215);
		else
			bresenham(&point, &point2, c, 0);
		point.y++;
		point2.y++;
		y++;
	}
}

static void	complete_minimap(t_cub3d *c)
{
	t_vector	point2;
	t_vector	pos;
	t_vector	temp_pos;

	pos.x = floor(c->player.pos.x);
	pos.y = floor(c->player.pos.y);
	temp_pos.x = (int)pos.x + 10;
	temp_pos.y = (int)pos.y + 10;
	point2.x = 41;
	point2.y = 31;
	while ((int)pos.x <= (int)temp_pos.x)
	{
		while ((int)pos.y <= (int)temp_pos.y)
		{
			if (c->minimap.map[(int)pos.x][(int)pos.y] == '8')
				draw_white_rect(c, 11, 11, point2);
			point2.x = point2.x + 11;
			pos.y = pos.y + 1;
		}
		pos.y = floor(c->player.pos.y);
		temp_pos.y = (int)pos.y + 10;
		point2.x = 41;
		point2.y = point2.y + 11;
		pos.x = pos.x + 1;
	}
}

void	draw_minimap(t_cub3d *c)
{
	complete_minimap(c);
	draw_player(c, 11, 11);
}
