/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:51:47 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 00:01:14 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_coordinate(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (-1);
}

void	get_path(int id, char *path, t_cub3d *c)
{
	if (id == 'N')
		c->map.no_path = ft_strdup(path);
	if (id == 'S')
		c->map.so_path = ft_strdup(path);
	if (id == 'W')
		c->map.we_path = ft_strdup(path);
	if (id == 'E')
		c->map.ea_path = ft_strdup(path);
}

void	get_coordinates(char *line, int *i, int id, t_cub3d *c)
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
	ignore_spaces(line, i);
	while (line[*i] != ' ' && line[*i] != '\n')
	{
		path[j] = line[*i];
		*i += 1;
		j++;
	}
	get_path(id, path, c);
	free(path);
}
