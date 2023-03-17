/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:51:47 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 11:42:02 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	return (TRUE);
}

void	get_path(t_map *map, int id, char *path, t_cub3d *c)
{
	if (check_path(path) == FALSE)
	{
		free(path);
		destroy_all(c);
		exit_error(MSG_ERR_OPEN_FILE, FALSE);
	}
	if (id == 'N')
		map->no_path = ft_strdup(path);
	else if (id == 'S')
		map->so_path = ft_strdup(path);
	else if (id == 'W')
		map->we_path = ft_strdup(path);
	else if (id == 'E')
		map->ea_path = ft_strdup(path);
}

void	get_coordinates(t_map *map, char *line, int *i, int id, t_cub3d *c)
{
	char	*path;
	int		j;

	*i += 1;
	if (line[*i] != 'O' && line[*i] != 'E' && line[*i] != 'A')
	{
		destroy_all(c);
		exit_error(MSG_ERR_TYPE_ID, FALSE);
	}
	path = ft_calloc(255, sizeof(char));
	j = 0;
	*i += 1;
	ft_ignore_spaces(line, i);
	while (line[*i] != ' ' && line[*i] != '\n')
	{
		path[j] = line[*i];
		*i += 1;
		j++;
	}
	get_path(map, id, path, c);
	free(path);
}
