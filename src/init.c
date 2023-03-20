/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:23:32 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 23:53:06 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initimage(t_image *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->win_width = 0;
	img->win_height = 0;
}

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

void	initcamera(t_camera *cam)
{
	cam->pixel = (t_vector){0};
	cam->plane = (t_vector){0};
	cam->speed.x = DEF_CAM_SPEED_X;
	cam->speed.y = DEF_CAM_SPEED_Y;
}

void	initplayer(t_player *player)
{
	initcamera(&player->camera);
	player->dir = (t_vector){0};
	player->pos = (t_vector){0};
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

void	initbutton(t_button *btn)
{
	btn->x = 0;
	btn->y = 0;
	btn->width = 0;
	btn->height = 0;
	btn->toggle = FALSE;
}

void	initmenu(t_menu *menu)
{
	menu->width_ratio = 0;
	menu->height_ratio = 0;
	menu->active = FALSE;
	initimage(&menu->img);
	initimage(&menu->resize);
	initbutton(&menu->fullscreen);
	initbutton(&menu->quit);
}
