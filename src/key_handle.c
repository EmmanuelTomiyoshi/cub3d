/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/14 18:31:15 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_exposure(t_rgb fg, float opacity, t_rgb color)
{
	int	brightness;

	blend(fg, color, opacity, &color);
	brightness = sqrt(0.299 * pow(color.r, 2) + 0.587 * pow(color.g, 2)
	+ 0.114 * pow(color.b, 2));
	if (brightness < COLOR_THRESHOLD_MAX && brightness > COLOR_THRESHOLD_MIN)
		return (TRUE);
	return (FALSE);
}

int	brightness(t_cub3d *c, int keycode)
{
	float	light;

	if (keycode == OPEN_BRACKET)
		light = ADD_LIGHT;
	else
		light = SUB_LIGHT;
	if (check_exposure(c->map.foreground, light, c->map.floor) == FALSE)
		return (0);
	blend(c->map.foreground, c->map.floor, light, &c->map.floor);
	c->map.f_color = get_rgb(c->map.floor.r, c->map.floor.g, c->map.floor.b);
	blend(c->map.foreground, c->map.ceiling, light, &c->map.ceiling);
	c->map.c_color = get_rgb(c->map.ceiling.r, c->map.ceiling.g, c->map.ceiling.b);
	blend(c->map.foreground, c->map.c_cube1, light, &c->map.c_cube1);
	c->map.cube1 = get_rgb(c->map.c_cube1.r, c->map.c_cube1.g, c->map.c_cube1.b);
	blend(c->map.foreground, c->map.c_cube2, light, &c->map.c_cube2);
	c->map.cube2 = get_rgb(c->map.c_cube2.r, c->map.c_cube2.g, c->map.c_cube2.b);
	return (0);
}

int	key_press(int keycode, t_cub3d *c)
{
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
	else if (keycode == KEY_SHIFT)
		c->player.run = TRUE;
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
