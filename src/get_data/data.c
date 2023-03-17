/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/16 21:43:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_type_identifier(char *line, t_map *map, t_cub3d *c)
{
	int	i;
	int	id_floor_ceiling;
	int	id_coordinate;

	i = 0;
	ft_ignore_spaces(line, &i);
	if (line[i] == '\n')
		return (0);
	id_floor_ceiling = is_floor_or_ceiling(line[i]);
	id_coordinate = is_coordinate(line[i]);
	if (id_floor_ceiling > 0 && ft_strlen(line) > 5)
		get_colors(map, line, &i, id_floor_ceiling, c);
	else if (id_coordinate > 0 && ft_strlen(line) > 2)
		get_coordinates(line, &i, id_coordinate, c);
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
		if (check_type_identifier(c->temp.line, map, c) == 1)
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
	init_map(c, one_line);
}
