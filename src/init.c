/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 12:54:13 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	square_colors(t_cub3d *c)
{
	itorgb(DARK_BLUE, &c->map.c_cube1);
	itorgb(LIGHT_BLUE, &c->map.c_cube2);
	c->map.cube1 = DARK_BLUE;
	c->map.cube2 = LIGHT_BLUE;
}

static void	menu(t_cub3d *c)
{
	c->menu.active = FALSE;
	c->menu.fullscreen.toggle = FALSE;
	c->menu.crosshair.toggle = FALSE;
	c->menu.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr,
		"./images/paused.xpm",
		&c->menu.img.win_width,
		&c->menu.img.win_height);
	c->menu.img.addr = mlx_get_data_addr(c->menu.img.ptr,
		&c->menu.img.bits_per_pixel, &c->menu.img.line_length,
		&c->menu.img.endian);
	c->menu.img.win_width = c->mlx.win.width;
	c->menu.img.win_height = c->mlx.win.height;
	get_btn_pos(&c->menu.fullscreen, 790, 389);
	get_btn_pos(&c->menu.crosshair, 790, 477);
	get_btn_size(&c->menu.fullscreen, 220, 45);
	get_btn_size(&c->menu.crosshair, 220, 45);
}

static void	mlx(t_cub3d *c)
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
}

static void	map_and_player(char *file, t_cub3d *c)
{
	c->map.file = ft_strdup(file);
	c->map.infos = 0;
	c->map.f_color = 0;
	c->map.c_color = 0;
	c->map.cube1 = 0;
	c->map.cube2 = 0;
	c->map.map = NULL;
	c->map.ea_path = NULL;
	c->map.we_path = NULL;
	c->map.so_path = NULL;
	c->map.no_path = NULL;
	c->dda.pixel = 0;
	c->dda.perpendicular = 0;
	c->player.camera.speed.x = 3.14;
	c->player.camera.speed.y = 356.86;
	c->hovering = FALSE;
	c->player.speed = DEFAULT_SPEED;
	itorgb(0, &c->map.foreground);
}

void	init(char **argv, t_cub3d *c)
{
	map_and_player(argv[1], c);
	mlx(c);
	square_colors(c);
	menu(c);
}
