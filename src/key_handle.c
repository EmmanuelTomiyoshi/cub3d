/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/12 18:47:29 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_win_size(t_cub3d *c)
{
	// printf("%d | %d\n", c->mlx.screen_width, c->mlx.screen_height);
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.image);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	c->mlx.win.ptr = mlx_new_window(c->mlx.ptr,
			c->mlx.screen_width,
			c->mlx.screen_height,
			WIN_NAME);
	c->mlx.img.image = mlx_new_image(c->mlx.ptr,
			c->mlx.screen_width,
			c->mlx.screen_height);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.image,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);

	return (0);
}

int	key_handle(int keycode, t_cub3d *c)
{
	if (keycode == KEY_ESC)
		end_loop(c);
	if (keycode == KEY_A)
		walk_left(c);
	if (keycode == KEY_W)
		walk_forward(c);
	if (keycode == KEY_S)
		walk_backward(c);
	if (keycode == KEY_D)
		walk_right(c);
	if (keycode == KEY_D)
		walk_right(c);
	if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		camera_move(keycode, 3.14, 356.86, c);
	// if (keycode == KEY_F11)
	// 	change_win_size(c);
	return (0);
}

int	key_press(int keycode, void *c)
{
	(void)c;
	(void)keycode;
	return (0);
}
