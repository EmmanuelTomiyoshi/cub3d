/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/10 17:04:10 by etomiyos         ###   ########.fr       */
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
	if (keycode == KEY_ARROW_LEFT)
		look_left(c);
	if (keycode == KEY_ARROW_RIGHT)
		look_right(c);
	return (0);
}

int	key_press(int keycode, void *c)
{
	(void)c;
	(void)keycode;
	return (0);
}