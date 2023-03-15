/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:20:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/15 00:20:38 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	player_speed(t_cub3d *c)
{
	float	temp;

	temp = c->player.speed * 1.1;
	if (temp < SPEED_THRESHOLD)
		c->player.speed *= 1.1;
}
