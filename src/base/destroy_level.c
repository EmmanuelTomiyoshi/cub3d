/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_level.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:13:46 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/18 10:15:10 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_file(t_map *map, t_cub3d *c)
{
	char	*tmp;

	tmp = get_next_line(map->fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(map->fd);
	}
	if (c->temp.line)
		free(c->temp.line);
	if (map->file)
		ft_free_array(map->map);
	free(map->file);
}

void	destroy_level_infos(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->level.count)
	{
		destroy_coordinates(&c->level.name[i]);
		destroy_file(&c->level.name[i], c);
		ft_free_array(c->level.name[i].map);
		if (c->level.name[i].minimap.map)
			ft_free_array(c->level.name[i].minimap.map);
		destroy_texture(c->level.name[i].ea_tex.img, c);
		destroy_texture(c->level.name[i].so_tex.img, c);
		destroy_texture(c->level.name[i].no_tex.img, c);
		destroy_texture(c->level.name[i].we_tex.img, c);
		i++;
	}
}

void	destroy_level(t_cub3d *c)
{
	destroy_level_infos(c);
	ft_free_array(c->level.files);
	free(c->level.name);
}