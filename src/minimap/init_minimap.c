/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:31 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/16 18:52:53 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_map(t_cub3d *c, int *i, int o)
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

static void	make_minimap(t_cub3d *c)
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
