/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:59:23 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 21:06:48 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initmaprgb(t_rgb *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void    inithit(t_hit *hit)
{
	hit->hit = FALSE;
	hit->side = 0;
}

void	initvector(t_vector *v)
{
	v->x = 0;
	v->y = 0;
}

void	initbutton(t_button *btn)
{
	btn->x = 0;
	btn->y = 0;
	btn->width = 0;
	btn->height = 0;
	btn->toggle = FALSE;
}

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