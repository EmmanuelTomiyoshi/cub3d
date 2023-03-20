/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 00:43:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_type_identifier(t_map *map, t_cub3d *c)
{
	int	i;
	int	id_floor_ceiling;
	int	id_coordinate;

	i = 0;
	ft_ignore_spaces(c->temp.line, &i);
	if (c->temp.line[i] == '\n')
		return (0);
	id_floor_ceiling = is_floor_or_ceiling(c->temp.line[i]);
	id_coordinate = is_coordinate(c->temp.line[i]);
	if (id_floor_ceiling > 0 && ft_strlen(c->temp.line) > 5)
		get_colors(map, &i, id_floor_ceiling, c);
	else if (id_coordinate > 0 && ft_strlen(c->temp.line) > 2)
		get_coordinates(map, &i, id_coordinate, c);
	else
	{
		destroy_all(c);
		exit_error(MSG_ERR_TYPE_ID, FALSE);
	}
	return (1);
}

void	get_colors_and_coordinates(t_map *map, t_cub3d *c)
{
	map->infos = 0;
	while (map->infos != 6)
	{
		c->temp.line = get_next_line(map->fd);
		if (c->temp.line == NULL)
		{
			destroy_all(c);
			exit_error(MSG_ERR_EMPTY_FILE, FALSE);
		}
		if (check_type_identifier(map, c) == 1)
			map->infos++;
		free(c->temp.line);
	}
}

void	get_map_content(t_map *map, char **one_line, t_cub3d *c)
{
	c->temp.line = get_next_line(map->fd);
	*one_line = ft_strdup("");
	while (c->temp.line)
	{
		*one_line = ft_merge(*one_line, c->temp.line);
		free(c->temp.line);
		c->temp.line = get_next_line(map->fd);
	}
	free(c->temp.line);
}

void	get_data(t_cub3d *c)
{
	char	*one_line;

	get_colors_and_coordinates(&c->map, c);
	get_map_content(&c->map, &one_line, c);
	get_map(&c->map, c, one_line);
	get_minimap(&c->map);
	get_texture(&c->map, c);
	get_level_info(c);
}
