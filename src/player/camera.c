/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 09:35:36 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_move(int keycode, double x, double y, t_cub3d *c)
{
	change_camera_speed(x, y, c);
	if (keycode == KEY_ARROW_LEFT)
		look_left(c);
	if (keycode == KEY_ARROW_RIGHT)
		look_right(c);
}

void	change_camera_speed(double x, double y, t_cub3d *c)
{
	c->player.camera.speed.x = x;
	c->player.camera.speed.y = y;
}

void	look_left(t_cub3d *c)
{
	rotate_vector(&c->player.dir, c->player.camera.speed.x);
	rotate_vector(&c->player.camera.plane, c->player.camera.speed.x);
}

void	look_right(t_cub3d *c)
{
	rotate_vector(&c->player.dir, c->player.camera.speed.y);
	rotate_vector(&c->player.camera.plane, c->player.camera.speed.y);
}
