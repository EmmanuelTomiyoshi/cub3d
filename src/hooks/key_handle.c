/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/15 00:49:32 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_movements(int keycode, t_cub3d *c)
{
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
	else if (keycode == KEY_SHIFT)
		c->player.run = TRUE;
}

int	key_press(int keycode, t_cub3d *c)
{
	key_movements(keycode, c);
	if (keycode == KEY_ESC)
		show_menu(c);
	else if (keycode == OPEN_BRACKET)
		brightness(c, keycode);
	else if (keycode == CLOSED_BRACKET)
		brightness(c, keycode);
	else if (keycode == KEY_M)
		camera_speed(0.25, -0.25, c);
	else if (keycode == KEY_N)
		camera_speed(-0.25, 0.25, c);
	else if (keycode == KEY_F11)
		change_win_size(c);
	return (0);
}

int	key_release(int keycode, t_cub3d *c)
{
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
	else if (keycode == KEY_SHIFT)
	{
		c->player.run = FALSE;
		c->player.speed = DEF_PLAYER_SPEED;
	}
	else if (keycode == KEY_F11)
		c->menu.fullscreen.toggle = FALSE;
	return (0);
}
