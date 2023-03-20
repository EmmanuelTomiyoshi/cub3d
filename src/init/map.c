/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:57:29 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 11:12:06 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initmaprgb(t_rgb *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void	initmaptexture(t_texture *tex)
{
	tex->height = 0;
	tex->width = 0;
	initimage(&tex->img);
}

void	initminimap(t_minimap *minimap)
{
	minimap->height = 0;
	minimap->width = 0;
	minimap->map = NULL;
}

void	initmap(t_map *map)
{
	map->fd = 0;
	map->infos = 0;
	map->c_color = 0;
	map->f_color = 0;
	initmaprgb(&map->ceiling);
	initmaprgb(&map->floor);
	map->file = NULL;
	map->map = NULL;
	map->ea_path = NULL;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	initmaptexture(&map->ea_tex);
	initmaptexture(&map->no_tex);
	initmaptexture(&map->so_tex);
	initmaptexture(&map->we_tex);
	initplayer(&map->player);
	initminimap(&map->minimap);
}
