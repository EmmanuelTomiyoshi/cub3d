/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/12 17:01:42 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handle(int keycode, t_cub3d *c)
{
	if (keycode == KEY_ESC)
		end_loop(c);
	if (keycode == KEY_A)
		walk_left(c);
	if (keycode == KEY_W)
		walk_forward(c);
	if (keycode == KEY_S)
		walk_backward(c);
	if (keycode == KEY_D)
		walk_right(c);
	if (keycode == KEY_D)
		walk_right(c);
	if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		camera_move(keycode, 3.14, 356.86, c);
	return (0);
}

int	key_press(int keycode, void *c)
{
	(void)c;
	(void)keycode;
	return (0);
}
