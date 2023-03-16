/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:17:25 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/16 16:29:04 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map(t_cub3d *c, int *i, int o)
{
	int	map_i;
	int	map_o;

	map_i = 0;
	map_o = 0;
	while (*i <= c->minimap.height - 5 && c->minimap.map[map_i] != NULL)
	{
		while (++o < 5)
			c->minimap.map[*i][o] = '1';
		while (c->map.map[map_i][map_o])
		{
			if (c->map.map[map_i][map_o])
			{
				c->minimap.map[*i][o] = c->map.map[map_i][map_o];
				o++;
				map_o++;
			}
		}
		while (o < c->minimap.width)
			c->minimap.map[*i][o++] = '1';
		c->minimap.map[*i][o] = '\0';
		if (c->minimap.map[map_i])
			map_i++;
		*i = *i + 1;
		map_o = 0;
		o = -1;
	}
}

void	make_minimap(t_cub3d *c)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (i != c->minimap.height)
	{
		while (((i < 5) || (i > c->minimap.height - 5)) && i != c->minimap.height)
		{
			while (o < c->minimap.width)
				c->minimap.map[i][o++] = '1';
			c->minimap.map[i][o] = '\0';
			o = 0;
			i++;
		}
		copy_map(c, &i, o);
		o = 0;
	}
	i = 0;
	while (i < c->minimap.width)
		c->minimap.map[5][i++] = '1';
	c->minimap.map[5][i] = '\0';
}

void	init_minimap(t_cub3d *c)
{
	int		i;
	int		o;
	int		max_size;

	i = 0;
	o = 0;
	max_size = 0;
	while (c->map.map[i])
	{
		while (c->map.map[i][o])
			o++;
		if (o > max_size)
			max_size = o;
		i++;
	}
	c->minimap.map = (char **)ft_calloc((i + 11), sizeof(char *));
	c->minimap.map[i + 10] = NULL;
	o = -1;
	while (++o < i + 10)
		c->minimap.map[o] = (char *)ft_calloc((max_size + 11), sizeof(char));
	c->minimap.width = max_size + 10;
	c->minimap.height = i + 9;
	make_minimap(c);
}

static void	draw_black_rect(t_cub3d *c, int width, int height, t_vector point)
{
	t_vector	point2;
	int			y;

	point2.x = point.x + width;
	point2.y = point.y;
	y = 0;
	while (y != height)
	{
		bresenham(&point, &point2, c, 0);
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
		bresenham(&point, &point2, c, 16777215);
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

	pos.x = floor(c->player.pos.x) + 5;
	pos.y = floor(c->player.pos.y) + 5;
	temp_pos.x = (int)pos.x + 11;
	temp_pos.y = (int)pos.y + 11;
	point2.x = 41;
	point2.y = 31;
	while ((int)pos.x <= (int)temp_pos.x)
	{
		while ((int)pos.y <= (int)temp_pos.y)
		{
			if (c->minimap.map[(int)pos.x][(int)pos.y] == '8')
				draw_white_rect(c, 11, 11, point2);
			else
				draw_black_rect(c, 11, 11, point2);
			point2.x = point2.x + 11;
			pos.y = pos.y + 1;
		}
		pos.y = floor(c->player.pos.y) + 5;
		temp_pos.y = (int)pos.y + 11;
		point2.x = 41;
		point2.y = point2.y + 11;
		pos.x = pos.x + 1;
	}
}

void	draw_minimap(t_cub3d *c)
{
	int			x;
	int			y;

	x = 39;
	y = 29;
	while (x <= 164)
	{
		my_pixel_put(&c->mlx.img, x, y, 16711680);
		my_pixel_put(&c->mlx.img, x, y + 1, 16711680);
		x++;
	}
	while (y <= 154)
	{
		my_pixel_put(&c->mlx.img, x, y, 16711680);
		my_pixel_put(&c->mlx.img, x - 1, y, 16711680);
		y++;
	}
	while (x >= 39)
	{
		my_pixel_put(&c->mlx.img, x, y, 16711680);
		my_pixel_put(&c->mlx.img, x, y - 1, 16711680);
		x--;
	}
	while (y >= 29)
	{
		my_pixel_put(&c->mlx.img, x, y, 16711680);
		my_pixel_put(&c->mlx.img, x + 1, y, 16711680);
		y--;
	}
	complete_minimap(c);
}
