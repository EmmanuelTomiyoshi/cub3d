/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 20:44:55 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_movements(int keycode, t_cub3d *c)
{
	if (keycode == KEY_A)
		c->key.move_left = TRUE;
	else if (keycode == KEY_W)
		c->key.move_foward = TRUE;
	else if (keycode == KEY_S)
		c->key.move_backwards = TRUE;
	else if (keycode == KEY_D)
		c->key.move_right = TRUE;
	else if (keycode == KEY_ARROW_LEFT)
		c->key.look_left = TRUE;
	else if (keycode == KEY_ARROW_RIGHT)
		c->key.look_right = TRUE;
	else if (keycode == KEY_SHIFT)
		c->key.run = TRUE;
}

int	key_press(int keycode, t_cub3d *c)
{
	key_movements(keycode, c);
	if (keycode == KEY_ESC)
		show_menu(c);
	else if (keycode == KEY_TAB)
		show_minimap(c);
	else if (keycode == KEY_J)
		camera_speed(0.25, -0.25, c);
	else if (keycode == KEY_K)
		camera_speed(-0.25, 0.25, c);
	else if (keycode == KEY_L)
		brightness(c);
	else if (keycode == KEY_E)
		distortion(c);
	else if (keycode == KEY_T)
		animate(c);
	else if (keycode == KEY_M)
		update_level(c);
	else if (keycode == KEY_F11)
		change_win_size(c);
	return (0);
}

int	key_release(int keycode, t_cub3d *c)
{
	if (keycode == KEY_A)
		c->key.move_left = FALSE;
	else if (keycode == KEY_W)
		c->key.move_foward = FALSE;
	else if (keycode == KEY_S)
		c->key.move_backwards = FALSE;
	else if (keycode == KEY_D)
		c->key.move_right = FALSE;
	else if (keycode == KEY_ARROW_LEFT)
		c->key.look_left = FALSE;
	else if (keycode == KEY_ARROW_RIGHT)
		c->key.look_right = FALSE;
	else if (keycode == KEY_SHIFT)
	{
		c->key.run = FALSE;
		c->key.speed = DEF_PLAYER_SPEED;
	}
	else if (keycode == KEY_F11)
		c->menu.fullscreen.toggle = FALSE;
	return (0);
}
