/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:00:15 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 00:03:11 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_left(t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = c->player.dir.x;
	temp_dir.y = c->player.dir.y;
	rotate_vector(&temp_dir, 90);
	temp_pos.x = c->player.pos.x + temp_dir.x * 0.05;
	temp_pos.y = c->player.pos.y + temp_dir.y * 0.05;
	temp_y = c->player.pos.y;
	if (c->map.map[(int)floor(c->player.pos.x)][(int)floor(temp_pos.y)] == '8')
		c->player.pos.y = temp_pos.y;
	if (c->map.map[(int)floor(temp_pos.x)][(int)floor(temp_y)] == '8')
		c->player.pos.x = temp_pos.x;
}

void	walk_forward(t_cub3d *c)
{
	t_vector	temp_pos;
	double		temp_y;

	temp_pos.x = c->player.pos.x + c->player.dir.x * 0.05;
	temp_pos.y = c->player.pos.y + c->player.dir.y * 0.05;
	temp_y = c->player.pos.y;
	if (c->map.map[(int)floor(c->player.pos.x)][(int)floor(temp_pos.y)] == '8')
		c->player.pos.y = temp_pos.y;
	if (c->map.map[(int)floor(temp_pos.x)][(int)floor(temp_y)] == '8')
		c->player.pos.x = temp_pos.x;
}

void	walk_backward(t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = c->player.dir.x;
	temp_dir.y = c->player.dir.y;
	rotate_vector(&temp_dir, 180);
	temp_pos.x = c->player.pos.x + temp_dir.x * 0.05;
	temp_pos.y = c->player.pos.y + temp_dir.y * 0.05;
	temp_y = c->player.pos.y;
	if (c->map.map[(int)floor(c->player.pos.x)][(int)floor(temp_pos.y)] == '8')
		c->player.pos.y = temp_pos.y;
	if (c->map.map[(int)floor(temp_pos.x)][(int)floor(temp_y)] == '8')
		c->player.pos.x = temp_pos.x;
}

void	walk_right(t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = c->player.dir.x;
	temp_dir.y = c->player.dir.y;
	rotate_vector(&temp_dir, 270);
	temp_pos.x = c->player.pos.x + temp_dir.x * 0.05;
	temp_pos.y = c->player.pos.y + temp_dir.y * 0.05;
	temp_y = c->player.pos.y;
	if (c->map.map[(int)floor(c->player.pos.x)][(int)floor(temp_pos.y)] == '8')
		c->player.pos.y = temp_pos.y;
	if (c->map.map[(int)floor(temp_pos.x)][(int)floor(temp_y)] == '8')
		c->player.pos.x = temp_pos.x;
}
