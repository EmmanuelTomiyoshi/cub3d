/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 16:20:24 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx.ptr);
	return (0);
}

int	handle_mouse(int x, int y, t_cub3d *c)
{
	static int	prev = 0;

	(void)y;
	if (!c->menu.active)
	{
		if (x < prev)
			look_left(c);
		else if (x > prev)
			look_right(c);
		prev = x;
	}
	else
		prev = x;
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
	mlx_mouse_hook(c->mlx.win.ptr, &mouse_callback, c);
	mlx_loop_hook(c->mlx.ptr, &draw, c);
	mlx_loop(c->mlx.ptr);
}
