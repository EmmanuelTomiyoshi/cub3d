/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_original.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 21:07:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initmlx(t_cub3d *c)
{
	c->mlx.ptr = mlx_init();
	c->mlx.win.ptr = mlx_new_window(c->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	c->mlx.img.ptr = mlx_new_image(c->mlx.ptr, WIDTH, HEIGHT);
	if (c->mlx.ptr == NULL || c->mlx.win.ptr == NULL || c->mlx.img.ptr == NULL)
		exit_error(MSG_ERR_MLX_INIT, FALSE);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.ptr,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);
	c->mlx.win.width = WIDTH;
	c->mlx.win.height = HEIGHT;
	c->mlx.img.win_width = WIDTH;
	c->mlx.img.win_height = HEIGHT;
	mlx_get_screen_size(c->mlx.ptr,
		&c->mlx.screen_width, &c->mlx.screen_height);
	c->mlx.screen_width -= 16;
	c->mlx.screen_height -= 32;
}

void    initcamera(t_camera *cam)
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

void	init(char **argv, t_cub3d *c)
{
	initmlx(c);
	initdda(&c->dda);
	initdraw(&c->draw);
	inittemp(&c->temp);
	inittoggle(&c->state);
	initkeys(&c->key);

	exit(1);
	(void)argv;
	// initplayer(c->p);								//
	// map_init(&c->map, argv[1]);
	// menu(c);								//
	// iall(c);
}


	// c->menu.quit.height = 0;
	// c->menu.quit.width = 0;
	// c->menu.quit.x = 0;
	// c->menu.quit.y = 0;

	// c->key.speed = DEF_PLAYER_SPEED;
	// c->map.player.camera.speed.x = DEF_CAM_SPEED_X;
	// c->map.player.camera.speed.y = DEF_CAM_SPEED_Y;
	//map->file = ft_strdup(file);

