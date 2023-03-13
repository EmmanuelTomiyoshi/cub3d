/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 09:33:37 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	fill_window(t_cub3d *c)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (j < c->mlx.win.height)
// 	{
// 		i = 0;
// 		while (i < c->mlx.win.width)
// 		{
// 			improved_mlx_pixel_put(&(c->mlx.img), i, j, 0x0000020);
// 			i++;
// 		}
// 		j++;
// 	}
// 	mlx_set_font(c->mlx.ptr, c->mlx.win.ptr, "10x20");
// 	mlx_string_put(c->mlx.ptr, c->mlx.win.ptr, 200, 300, 0x0FFFF00, "FONT TEST");
// 	mlx_set_font(c->mlx.ptr, c->mlx.win.ptr, "7x13eurobold");
// 	mlx_string_put(c->mlx.ptr, c->mlx.win.ptr, 200, 600, 0x0FF00FF, "01234567890");
// }

// int	render(t_cub3d *c)
// {
// 	mlx_put_image_to_window(c->mlx.ptr, c->mlx.win.ptr, c->mlx.img.image, 0, 0);
// 	fill_window(c);
// 	return (0);
// }

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx.ptr);
	return (0);
}

int	handle_mouse(int x, int y, t_cub3d *c)
{
	static int	prev = 0;

	(void)y;
	// mlx_mouse_move(c->mlx.ptr, c->mlx.win.ptr, 400, 400);
	// mlx_mouse_hide(c->mlx.ptr, c->mlx.win.ptr);
	if (x < prev)
		look_left(c);
	else if (x > prev)
		look_right(c);
	prev = x;
	// camera_move(KEY_ARROW_LEFT, 1.7, 358.3, c);
	return (0);
}

void	blend(t_rgb fg, t_rgb bg, float opacity, t_rgb *result)
{
	result->r = fg.r * opacity + bg.r * (1 - opacity);
	result->g = fg.g * opacity + bg.g * (1 - opacity);
	result->b = fg.b * opacity + bg.b * (1 - opacity);
}

void	alpha_blending(t_cub3d *c)
{
	(void)c;
	t_rgb	fg;
	t_rgb	bg;
	t_rgb	result;
	
	fg.r = 255;
	fg.g = 0;
	fg.b = 0;
	
	bg.r = 255;
	bg.g = 255;
	bg.b = 255;
	
	blend(fg, bg, 0.5, &result);
	printf("Resulting color: (%d, %d, %d)\n", result.r, result.g, result.b);
}

void	loop(t_cub3d *c)
{
	mlx_hook(c->mlx.win.ptr, 17, 0, &end_loop, c);
	mlx_hook(c->mlx.win.ptr, 02, 1L << 0, key_press, c);
	mlx_hook(c->mlx.win.ptr, 03, 1L << 1, key_release, c);
	mlx_hook(c->mlx.win.ptr, MotionNotify, PointerMotionMask, handle_mouse, c);
	// alpha_blending(c);
	mlx_loop_hook(c->mlx.ptr, &draw, c);
	mlx_loop(c->mlx.ptr);
}
