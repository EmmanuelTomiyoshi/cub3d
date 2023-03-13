/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/13 00:03:09 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub3d *c)
{
	if (keycode == KEY_ESC)
		end_loop(c);
	else if (keycode == KEY_A)
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
	return (0);
}

int	key_release(int keycode, t_cub3d *c)
{
	if (keycode == KEY_ESC)
		end_loop(c);
	else if (keycode == KEY_A)
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
	return (0);
}
