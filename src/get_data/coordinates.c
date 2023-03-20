/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:51:47 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 14:31:18 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	return (TRUE);
}

static void	get_path(t_map *map, int id, char *path, t_cub3d *c)
{
	if (check_path(path) == FALSE)
	{
		free(path);
		destroy_all(c);
		exit_error(MSG_ERR_OPEN_FILE, FALSE);
	}
	if (id == 'N' && map->no_path == NULL)
		map->no_path = ft_strdup(path);
	else if (id == 'S' && map->so_path == NULL)
		map->so_path = ft_strdup(path);
	else if (id == 'W' && map->we_path == NULL)
		map->we_path = ft_strdup(path);
	else if (id == 'E' && map->ea_path == NULL)
		map->ea_path = ft_strdup(path);
}

void	get_coordinates(t_map *map, int *i, int id, t_cub3d *c)
{
	char	*path;
	int		j;

	*i += 1;
	if (c->temp.line[*i] != 'O' && c->temp.line[*i] != 'E'
		&& c->temp.line[*i] != 'A')
	{
		destroy_all(c);
		exit_error(MSG_ERR_TYPE_ID, FALSE);
	}
	path = ft_calloc(255, sizeof(char));
	j = 0;
	*i += 1;
	ft_ignore_spaces(c->temp.line, i);
	while (c->temp.line[*i] != ' ' && c->temp.line[*i] != '\n')
	{
		path[j] = c->temp.line[*i];
		*i += 1;
		j++;
	}
	get_path(map, id, path, c);
	free(path);
}
