/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/08 20:00:51 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ignore_spaces(char *line, int *i)
{
	while (line[*i] == ' ')
		*i += 1;
}

int	check_type_identifier(char *line, t_cub3d *c)
{
	int	i;
	int	id_floor_ceiling;
	int	id_coordinate;

	i = 0;
	ignore_spaces(line, &i);
	if (line[i] == '\n')
		return (0);
	id_floor_ceiling = is_floor_or_ceiling(line[i]);
	id_coordinate = is_coordinate(line[i]);
	if (id_floor_ceiling > 0 && ft_strlen(line) > 5)
		get_colors(line, &i, id_floor_ceiling, c);
	else if (id_coordinate > 0 && ft_strlen(line) > 2)
		get_coordinates(line, &i, id_coordinate, c);
	else
	{
		destroy_all(c);
		exit_error(MSG_ERR_TYPE_ID, FALSE);
	}
	return (1);
}

void	get_data(t_cub3d *c)
{
	char	*line;
	char	*one_line;

	c->map.infos = 0;
	while (c->map.infos != 6)
	{
		line = get_next_line(c->map.fd);
		if (check_type_identifier(line, c) == 1)
			c->map.infos++;
		free(line);
	}
	line = get_next_line(c->map.fd);
	one_line = ft_strdup("");
	while (line)
	{
		one_line = ft_merge(one_line, line);
		free(line);
		line = get_next_line(c->map.fd);
	}
	free(line);
	init_map(c, one_line);
}
