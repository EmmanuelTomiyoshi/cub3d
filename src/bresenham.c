/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:03:24 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/08 15:26:11 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_cub3d *c, int x, int y, int color)
{
	char	*dst;

	if (x <= WIDTH && y <= HEIGHT && y >= 0 && x >= 0)
	{
		dst = c->img.addr + (y * c->img.line_length + x
				* (c->img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
	}
}

void	lower_slope(t_line *l, t_cub3d *c, int color)
{
	int	d;
	int	i;
	int	o;

	i = -1;
	if (l->start_y > l->end_y)
		o = -1;
	else
		o = 1;
	my_pixel_put(c, l->start_x, l->start_y, color);
	d = (2 * fabs(l->dy)) - fabs(l->dx);
	while (++i < fabs(l->dx))
	{
		l->start_x = l->start_x + 1;
		if (d < 0)
			d = d + (2 * fabs(l->dy));
		else
		{
			l->start_y = l->start_y + o;
			d = d + (2 * fabs(l->dy)) - (2 * fabs(l->dx));
		}
		my_pixel_put(c, l->start_x, l->start_y, color);
	}
}

void	bigger_slope(t_line *l, t_cub3d *c, int color)
{
	int	d;
	int	i;
	int	o;

	i = -1;
	if (l->start_y > l->end_y)
		o = -1;
	else
		o = 1;
	my_pixel_put(c, l->start_x, l->start_y, color);
	d = (2 * fabs(l->dx) - fabs(l->dy));
	while (++i < fabs(l->dy))
	{
		l->start_y = l->start_y + o;
		if (d < 0)
			d = d + (2 * fabs(l->dx));
		else
		{
			l->start_x = l->start_x + 1;
			d = d + (2 * fabs(l->dx)) - (2 * fabs(l->dy));
		}
		my_pixel_put(c, l->start_x, l->start_y, color);
	}
}

void	drawline(t_line *line, t_cub3d *c, int color)
{
	line->dx = line->end_x - line->start_x;
	line->dy = line->end_y - line->start_y;
	if (fabs(line->dx) > fabs(line->dy))
		lower_slope(line, c, color);
	else
		bigger_slope(line, c, color);
}

void	bresenham(t_point *point1, t_point *point2, t_cub3d *c, int color)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (point1->x < point2->x)
	{
		line->start_x = point1->x;
		line->end_x = point2->x;
		line->start_y = point1->y;
		line->end_y = point2->y;
	}
	else
	{
		line->end_x = point1->x;
		line->start_x = point2->x;
		line->end_y = point1->y;
		line->start_y = point2->y;
	}
	drawline(line, c, color);
	free(line);
}
