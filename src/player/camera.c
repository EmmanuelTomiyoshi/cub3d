/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 15:18:58 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera(t_cub3d *c)
{
	if (c->player.look_left)
		look_left(c);
	if (c->player.look_right)
		look_right(c);
}

t_bool	check_speed(double x, t_cub3d *c)
{
	if (c->player.camera.speed.x + x > 1 && c->player.camera.speed.x + x < 11)
		return (TRUE);
	return (FALSE);
}

void	camera_speed(double x, double y, t_cub3d *c)
{
	if (check_speed(x, c) == FALSE)
		return ;
	c->player.camera.speed.x += x;
	c->player.camera.speed.y += y;
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
