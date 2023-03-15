/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/15 00:20:20 by etomiyos         ###   ########.fr       */
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
