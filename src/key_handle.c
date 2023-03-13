/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/13 19:21:36 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_win_size(int width, int height, t_cub3d *c)
{
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.image);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	(void)width;
	(void)height;
	c->mlx.win.width = c->mlx.screen_width - 16;
	c->mlx.win.height = c->mlx.screen_height - 32;
	c->mlx.win.ptr = mlx_new_window(c->mlx.ptr,
			c->mlx.win.width,
			c->mlx.win.height,
			WIN_NAME);
	c->mlx.img.image = mlx_new_image(c->mlx.ptr,
			c->mlx.win.width,
			c->mlx.win.height);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.image,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);
	loop(c);
	return (0);
}

int	key_press(int keycode, t_cub3d *c)
{
	if (keycode == KEY_ESC)
		show_menu(c);
	if (keycode == KEY_A)
		c->player.move_left = TRUE;
	else if (keycode == KEY_W)
		c->player.move_foward = TRUE;
	else if (keycode == KEY_S)
		c->player.move_backwards = TRUE;
	else if (keycode == KEY_D)
		c->player.move_right = TRUE;
	else if (keycode == KEY_ARROW_LEFT)
		c->player.look_left = TRUE;
	else if (keycode == KEY_ARROW_RIGHT)
		c->player.look_right = TRUE;
	else if (keycode == KEY_F11)
		change_win_size(1024, 768, c);
	return (0);
}

int	key_release(int keycode, t_cub3d *c)
{
	// if (keycode == KEY_ESC)
	// 	end_loop(c);
	if (keycode == KEY_A)
		c->player.move_left = FALSE;
	else if (keycode == KEY_W)
		c->player.move_foward = FALSE;
	else if (keycode == KEY_S)
		c->player.move_backwards = FALSE;
	else if (keycode == KEY_D)
		c->player.move_right = FALSE;
	else if (keycode == KEY_ARROW_LEFT)
		c->player.look_left = FALSE;
	else if (keycode == KEY_ARROW_RIGHT)
		c->player.look_right = FALSE;
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		camera_move(keycode, 3.14, 356.86, c);
	return (0);
}
