/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/12 18:50:35 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_window(t_cub3d *c)
{
	int	i;
	int	j;

	j = 0;
	while (j < c->mlx.win.height)
	{
		i = 0;
		while (i < c->mlx.win.width)
		{
			improved_mlx_pixel_put(&(c->mlx.img), i, j, 0x0000020);
			i++;
		}
		j++;
	}
	mlx_set_font(c->mlx.ptr, c->mlx.win.ptr, "10x20");
	mlx_string_put(c->mlx.ptr, c->mlx.win.ptr, 200, 300, 0x0FFFF00, "FONT TEST");
	mlx_set_font(c->mlx.ptr, c->mlx.win.ptr, "7x13eurobold");
	mlx_string_put(c->mlx.ptr, c->mlx.win.ptr, 200, 600, 0x0FF00FF, "01234567890");
}

int	render(t_cub3d *c)
{
	mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->mlx.img.image, 0, 0);
	fill_window(c);
	return (0);
}

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx.ptr);
	return (0);
}

int	handle_mouse(int x, int y, t_cub3d *c)
{
	static int	prev = 0;

	(void)y;
	if (x < prev)
		camera_move(KEY_ARROW_LEFT, 1.7, 358.3, c);
	else if (x > prev)
		camera_move(KEY_ARROW_RIGHT, 1.7, 358.3, c);
	prev = x;
	return (0);
}

void	loop(t_cub3d *c)
{
	mlx_hook(c->mlx.win.ptr, 17, 0, end_loop, c);
	mlx_hook(c->mlx.win.ptr, 2, 1L << 0, key_press, c);
	mlx_hook(c->mlx.win.ptr, MotionNotify, PointerMotionMask, handle_mouse, c);
	mlx_key_hook(c->mlx.win.ptr, key_handle, c);
	mlx_loop_hook(c->mlx.ptr, &draw, c);
	mlx_loop(c->mlx.ptr);
}
