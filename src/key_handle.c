/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/12 23:28:08 by etomiyos         ###   ########.fr       */
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

void	show_menu(t_cub3d *c)
{
	t_rgb	foreground;

	itorgb(0, &foreground);
	blend(foreground, c->map.floor, MENU_OPACITY, &c->map.floor);
	c->map.f_color = get_rgb(c->map.floor.r, c->map.floor.g, c->map.floor.b);
	blend(foreground, c->map.ceiling, MENU_OPACITY, &c->map.ceiling);
	c->map.c_color = get_rgb(c->map.ceiling.r, c->map.ceiling.g, c->map.ceiling.b);
	blend(foreground, c->map.c_cube1, MENU_OPACITY, &c->map.c_cube1);
	c->map.cube1 = get_rgb(c->map.c_cube1.r, c->map.c_cube1.g, c->map.c_cube1.b);
	blend(foreground, c->map.c_cube2, MENU_OPACITY, &c->map.c_cube2);
	c->map.cube2 = get_rgb(c->map.c_cube2.r, c->map.c_cube2.g, c->map.c_cube2.b);
}

int	key_handle(int keycode, t_cub3d *c)
{
	if (keycode == KEY_ESC)
		end_loop(c);
	if (keycode == 112)
		show_menu(c);
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
	if (keycode == KEY_F11)
		change_win_size(1024, 768, c);
	return (0);
}

int	key_press(int keycode, void *c)
{
	(void)c;
	(void)keycode;
	return (0);
}
