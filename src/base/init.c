/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/15 18:23:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	intorgb(int *r, int *g, int *b, unsigned int *color)
{
	*r = (*color >> 16) & 0xFF;
	*g = (*color >> 8) & 0xFF;
	*b = *color & 0xFF;
}

unsigned int	increase_brightness(unsigned int *color, float opacity)
{
	int	r;
	int	g;
	int	b;

	intorgb(&r, &g, &b, color);
	r *= opacity;
	g *= opacity;
	b *= opacity;
	return (r << 16) | (g << 8) | b;
}

unsigned int	decrease_brightness(unsigned int *color, float opacity)
{
	int	r;
	int	g;
	int	b;

	intorgb(&r, &g, &b, color);
	r /= opacity;
	g /= opacity;
	b /= opacity;
	return (r << 16) | (g << 8) | b;
}

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
	c->menu.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr,
			"./assets/images/paused.xpm",
			&c->menu.img.win_width,
			&c->menu.img.win_height);
	c->menu.img.addr = mlx_get_data_addr(c->menu.img.ptr,
			&c->menu.img.bits_per_pixel, &c->menu.img.line_length,
			&c->menu.img.endian);
	c->menu.img.win_width = c->mlx.win.width;
	c->menu.img.win_height = c->mlx.win.height;
	get_btn_size(&c->menu.quit, 180, 64);

	get_btn_pos(&c->menu.quit, 54, 580);
	get_btn_size(&c->menu.quit, 180, 72);
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
	c->mlx.screen_width -= 16;
	c->mlx.screen_height -= 32;
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
	c->player.camera.speed.x = DEF_CAM_SPEED_X;
	c->player.camera.speed.y = DEF_CAM_SPEED_Y;
	c->hovering = FALSE;
	c->player.speed = DEF_PLAYER_SPEED;
	itorgb(0, &c->map.foreground);
}

static void	textures(t_cub3d *c)
{
	c->draw = (t_draw){0};//
	c->exposure = FALSE;
	c->lighter = FALSE;
	c->darker = FALSE;
	c->brightness = 0;
	c->mlx.ea_tex = (t_texture){0};
	c->mlx.so_tex = (t_texture){0};
	c->mlx.no_tex = (t_texture){0};
	c->mlx.we_tex = (t_texture){0};
}

void	init(char **argv, t_cub3d *c)
{
	map_and_player(argv[1], c);
	textures(c);
	mlx(c);
	square_colors(c);
	menu(c);
}