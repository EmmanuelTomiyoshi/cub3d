/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:17:24 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 15:54:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_level_fd(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->level.count)
	{
		c->level.temp = ft_strjoin("assets/maps/", c->level.files[i]);
		c->level.name[i].fd = open(c->level.temp, O_RDONLY);
		if (c->level.name[i].fd == -1)
		{
			free(c->level.temp);
			destroy_level(c);
			exit_error(MSG_ERR_LEVEL_FILE, FALSE);
		}
		free(c->level.temp);
		i++;
	}
}

void	init_texture(t_map *map)
{
	map->ea_tex.img.ptr = NULL;
	map->so_tex.img.ptr = NULL;
	map->no_tex.img.ptr = NULL;
	map->we_tex.img.ptr = NULL;
}

void	get_level_colors_and_coordinates(t_cub3d *c)
{
	int		i;
	char	*one_line;

	i = 0;
	while (i < c->level.count)
	{
		get_colors_and_coordinates(&c->level.name[i], c);
		get_map_content(&c->level.name[i], &one_line, c);
		init_map(&c->level.name[i], c, one_line);
		init_minimap(&c->level.name[i]);
		init_texture(&c->level.name[i]);
		get_texture(&c->level.name[i], c);
		i++;
	}
}

void	update_level(t_cub3d *c)
{
	static int	i = 0;
	t_map		temp;

	if (i == 0)
		temp = c->map;
	if (i == c->level.count)
	{
		i = 0;
		c->map = temp;
	}
	c->map = c->level.name[i];
	i++;
}
