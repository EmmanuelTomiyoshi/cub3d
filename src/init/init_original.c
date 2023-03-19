/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/18 15:52:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	menu(t_cub3d *c)
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

void	map_init(t_map *map, char *file)
{
	map->file = ft_strdup(file);

	//
	map->infos = 0;
	map->f_color = 0;
	map->c_color = 0;
	map->map = NULL;
	map->ea_path = NULL;
	map->we_path = NULL;
	map->so_path = NULL;
	map->no_path = NULL;
	map->ea_tex.img.ptr = NULL;
	map->so_tex.img.ptr = NULL;
	map->no_tex.img.ptr = NULL;
	map->we_tex.img.ptr = NULL;
}

static void	player(t_cub3d *c)
{
	c->dda.pixel = 0;
	c->dda.perpendicular = 0;

	c->state.light_mode = FALSE;
	c->state.distortion = FALSE;
	c->state.animate = FALSE;
	c->state.mini_map = FALSE;

	//
	c->key.speed = DEF_PLAYER_SPEED;
	c->map.player.camera.speed.x = DEF_CAM_SPEED_X;
	c->map.player.camera.speed.y = DEF_CAM_SPEED_Y;
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

void    initdda(t_dda *dda)
{
	dda->pixel = 0;
	dda->perpendicular = 0;
	inithit(&dda->hit);
	initvector(&dda->delta);
	initvector(&dda->to_side);
	initvector(&dda->step);
	initvector(&dda->raydir);
	initvector(&dda->line_size);
	initvector(&dda->wall_pos);
}

void	initdraw(t_draw *draw)
{
	draw->wall_line_height = 0;
	draw->start = 0;
	draw->end = 0;
	draw->tex_x = 0;
	draw->tex_y = 0;
	draw->wall_x = 0;
	draw->tex_pos = 0;
	draw->step = 0;
	draw->color = 0;
}

void	inittemp(t_temp *tmp)
{
	tmp->line = NULL;
}

void	inittoggle(t_toggle *state)
{
	state->animate = FALSE;
	state->distortion = FALSE;
	state->light_mode = FALSE;
	state->mini_map = FALSE;
}

void	initkeys(t_keyhandle *key)
{
	key->move_left = FALSE;
	key->move_right = FALSE;
	key->move_foward = FALSE;
	key->move_backwards = FALSE;
	key->look_right = FALSE;
	key->look_left = FALSE;
	key->run = FALSE;
	key->speed = DEF_PLAYER_SPEED;
}

void	init(char **argv, t_cub3d *c)
{
	//
	new_mlx(c);
	player(c);								//
	initdda(&c->dda);
	initdraw(&c->draw);
	inittemp(&c->temp);
	inittoggle(&c->state);
	initkeys(&c->key);
	map_init(&c->map, argv[1]);
	menu(c);								//
	// iall(c);
}


	// c->menu.quit.height = 0;
	// c->menu.quit.width = 0;
	// c->menu.quit.x = 0;
	// c->menu.quit.y = 0;