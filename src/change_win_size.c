/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_win_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:17:34 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 10:10:31 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_win_size(int width, int height, t_cub3d *c)
{
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.ptr);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	(void)width;
	(void)height;
	c->mlx.win.width = c->mlx.screen_width - 16;
	c->mlx.win.height = c->mlx.screen_height - 32;
	c->menu.img.win_width = c->mlx.screen_width - 16;
	c->menu.img.win_height = c->mlx.screen_height - 32;
	c->mlx.img.win_width = c->mlx.screen_width - 16;
	c->mlx.img.win_height = c->mlx.screen_height - 32;
	c->mlx.win.ptr = mlx_new_window(c->mlx.ptr,
			c->mlx.win.width,
			c->mlx.win.height,
			WIN_NAME);
	c->mlx.img.ptr = mlx_new_image(c->mlx.ptr,
			c->mlx.win.width,
			c->mlx.win.height);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.ptr,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);
	loop(c);
	return (0);
}
