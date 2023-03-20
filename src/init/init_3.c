/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:58:28 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 21:07:07 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	menu(t_cub3d *c)
{
	//
	c->menu.active = FALSE;
	c->menu.fullscreen.toggle = FALSE;

	//
	c->menu.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr,
			"./assets/images/paused.xpm",
			&c->menu.img.win_width,
			&c->menu.img.win_height);
	if (c->menu.img.ptr == NULL)
	{
		destroy_all(c);
		exit_error(MSG_ERR_MISSING_MENU, FALSE);
	}
	c->menu.img.addr = mlx_get_data_addr(c->menu.img.ptr,
			&c->menu.img.bits_per_pixel, &c->menu.img.line_length,
			&c->menu.img.endian);
	c->menu.img.win_width = c->mlx.win.width;
	c->menu.img.win_height = c->mlx.win.height;


	//
	c->menu.resize.ptr = NULL;
	c->menu.resize.addr = NULL;
	c->menu.width_ratio = 0;
	c->menu.height_ratio = 0;
}

void	initmaptexture(t_texture *tex)
{
	tex->height = 0;
	tex->width = 0;
	initimage(&tex->img);
}

void    initminimap(t_minimap *minimap)
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