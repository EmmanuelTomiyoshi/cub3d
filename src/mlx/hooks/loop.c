/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/16 12:42:03 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx.ptr);
	return (0);
}

void	loop(t_cub3d *c)
{
	mlx_hook(c->mlx.win.ptr, 17, 0, &end_loop, c);
	mlx_hook(c->mlx.win.ptr, 25, 1L << 18, &change_win_size, c);
	mlx_hook(c->mlx.win.ptr, 02, 1L << 0, key_press, c);
	mlx_hook(c->mlx.win.ptr, 03, 1L << 1, key_release, c);
	mlx_hook(c->mlx.win.ptr, MotionNotify, PointerMotionMask, handle_mouse, c);
	mlx_mouse_hook(c->mlx.win.ptr, &mouse_callback, c);
	mlx_loop_hook(c->mlx.ptr, &draw, c);
	mlx_loop(c->mlx.ptr);
}
