/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:23:32 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 11:11:58 by mtomomit         ###   ########.fr       */
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
	img->width = 0;
	img->height = 0;
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
