/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 01:35:41 by etomiyos         ###   ########.fr       */
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
	if (x < prev)
		look_left(c);
	else if (x > prev)
		look_right(c);
	prev = x;
	return (0);
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
