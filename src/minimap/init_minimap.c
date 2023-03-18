/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:31 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/18 10:12:19 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_map(t_map *map, int *i, int o)
{
	int	map_i;
	int	map_o;

	map_i = -1;
	map_o = 0;
	while (*i <= map->minimap.height - 5 && map->minimap.map[++map_i] != NULL)
	{
		while (o < 5 || (o < map->minimap.width && o != 5))
			map->minimap.map[*i][o++] = '1';
		while (map->map[map_i][map_o])
		{
			if (map->map[map_i][map_o])
			{
				map->minimap.map[*i][o] = map->map[map_i][map_o];
				o++;
				map_o++;
			}
		}
		*i = *i + 1;
		map_o = 0;
		o = 0;
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
		while (((i < 5) || (i > map->minimap.height - 5)) \
				&& i != map->minimap.height)
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
	int		o;

	map->minimap.height = 0;
	o = 0;
	map->minimap.width = 0;
	while (map->map[map->minimap.height] != NULL)
	{
		while (map->map[map->minimap.height][o] != '\0')
			o++;
		if (o > map->minimap.width)
			map->minimap.width = o;
		map->minimap.height++;
		o = 0;
	}
	map->minimap.map = (char **)ft_calloc((map->minimap.height + 11), \
					sizeof(char *));
	map->minimap.map[map->minimap.height + 10] = NULL;
	o = -1;
	while (++o < map->minimap.height + 10)
		map->minimap.map[o] = (char *)ft_calloc((map->minimap.width + 11), \
						sizeof(char));
	map->minimap.width = map->minimap.width + 10;
	map->minimap.height = map->minimap.height + 9;
	make_minimap(map);
}
