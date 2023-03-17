/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:31 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 16:45:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_map(t_map *map, int *i, int o)
{
	int	map_i;
	int	map_o;

	map_i = 0;
	map_o = 0;
	while (*i <= map->minimap.height - 5 && map->minimap.map[map_i] != NULL)
	{
		while (++o < 5)
			map->minimap.map[*i][o] = '1';
		while (map->map[map_i][map_o])
		{
			if (map->map[map_i][map_o])
			{
				map->minimap.map[*i][o] = map->map[map_i][map_o];
				o++;
				map_o++;
			}
		}
		while (o < map->minimap.width)
			map->minimap.map[*i][o++] = '1';
		map->minimap.map[*i][o] = '\0';
		if (map->minimap.map[map_i])
			map_i++;
		*i = *i + 1;
		map_o = 0;
		o = -1;
	}
}

static void	make_minimap(t_map *map)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (i != map->minimap.height)
	{
		while (((i < 5) || (i > map->minimap.height - 5)) && i != map->minimap.height)
		{
			while (o < map->minimap.width)
				map->minimap.map[i][o++] = '1';
			map->minimap.map[i][o] = '\0';
			o = 0;
			i++;
		}
		copy_map(map, &i, o);
		o = 0;
	}
	i = 0;
	while (i < map->minimap.width)
		map->minimap.map[5][i++] = '1';
	map->minimap.map[5][i] = '\0';
}

void	init_minimap(t_map *map)
{
	int		i;
	int		o;
	int		max_size;

	i = 0;
	o = 0;
	max_size = 0;
	while (map->map[i])
	{
		while (map->map[i][o])
			o++;
		if (o > max_size)
			max_size = o;
		o = 0;
		i++;
	}
	map->minimap.map = (char **)ft_calloc((i + 11), sizeof(char *));
	map->minimap.map[i + 10] = NULL;
	o = -1;
	while (++o < i + 10)
		map->minimap.map[o] = (char *)ft_calloc((max_size + 11), sizeof(char));
	map->minimap.width = max_size + 10;
	map->minimap.height = i + 9;
	make_minimap(map);
}
