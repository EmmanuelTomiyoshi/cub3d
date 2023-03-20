/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:03:24 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 00:00:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	lower_slope(t_line *l, t_cub3d *c, int color)
{
	int	d;
	int	i;
	int	o;

	i = -1;
	if (l->start_y > l->end_y)
		o = -1;
	else
		o = 1;
	my_pixel_put(&c->mlx.img, l->start_x, l->start_y, color);
	d = (2 * fabs((double)l->dy)) - fabs((double)l->dx);
	while (++i < fabs((double)l->dx))
	{
		l->start_x = l->start_x + 1;
		if (d < 0)
			d = d + (2 * fabs((double)l->dy));
		else
		{
			l->start_y = l->start_y + o;
			d = d + (2 * fabs((double)l->dy)) - (2 * fabs((double)l->dx));
		}
		my_pixel_put(&c->mlx.img, l->start_x, l->start_y, color);
	}
}

static void	bigger_slope(t_line *l, t_cub3d *c, int color)
{
	int	d;
	int	i;
	int	o;

	i = -1;
	if (l->start_y > l->end_y)
		o = -1;
	else
		o = 1;
	my_pixel_put(&c->mlx.img, l->start_x, l->start_y, color);
	d = (2 * fabs((double)l->dx) - fabs((double)l->dy));
	while (++i < fabs((double)l->dy))
	{
		l->start_y = l->start_y + o;
		if (d < 0)
			d = d + (2 * fabs((double)l->dx));
		else
		{
			l->start_x = l->start_x + 1;
			d = d + (2 * fabs((double)l->dx)) - (2 * fabs((double)l->dy));
		}
		my_pixel_put(&c->mlx.img, l->start_x, l->start_y, color);
	}
}

static void	drawline(t_line *line, t_cub3d *c, int color)
{
	line->dx = line->end_x - line->start_x;
	line->dy = line->end_y - line->start_y;
	if (fabs((double)line->dx) > fabs((double)line->dy))
		lower_slope(line, c, color);
	else
		bigger_slope(line, c, color);
}

void	bresenham(t_vector *point1, t_vector *point2, t_cub3d *c, int color)
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
