/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:00:15 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 12:59:56 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_speed(t_cub3d *c)
{
	float	temp;

	temp = c->player.speed * 1.1;
	if (temp < SPEED_THRESHOLD)
		c->player.speed *= 1.1;
}

void	movements(t_cub3d *c)
{
	if (c->player.run)
		player_speed(c);
	if (c->player.move_backwards)
		walk_backwards(c);
	if (c->player.move_foward)
		walk_forward(c);
	if (c->player.move_left)
		walk_left(c);
	if (c->player.move_right)
		walk_right(c);
}

void	walk_left(t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = c->player.dir.x;
	temp_dir.y = c->player.dir.y;
	rotate_vector(&temp_dir, 90);
	temp_pos.x = c->player.pos.x + temp_dir.x * c->player.speed;
	temp_pos.y = c->player.pos.y + temp_dir.y * c->player.speed;
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

	temp_pos.x = c->player.pos.x + c->player.dir.x * c->player.speed;
	temp_pos.y = c->player.pos.y + c->player.dir.y * c->player.speed;
	temp_y = c->player.pos.y;
	if (c->map.map[(int)floor(c->player.pos.x)][(int)floor(temp_pos.y)] == '8')
		c->player.pos.y = temp_pos.y;
	if (c->map.map[(int)floor(temp_pos.x)][(int)floor(temp_y)] == '8')
		c->player.pos.x = temp_pos.x;
}

void	walk_backwards(t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = c->player.dir.x;
	temp_dir.y = c->player.dir.y;
	rotate_vector(&temp_dir, 180);
	temp_pos.x = c->player.pos.x + temp_dir.x * c->player.speed;
	temp_pos.y = c->player.pos.y + temp_dir.y * c->player.speed;
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
	temp_pos.x = c->player.pos.x + temp_dir.x * c->player.speed;
	temp_pos.y = c->player.pos.y + temp_dir.y * c->player.speed;
	temp_y = c->player.pos.y;
	if (c->map.map[(int)floor(c->player.pos.x)][(int)floor(temp_pos.y)] == '8')
		c->player.pos.y = temp_pos.y;
	if (c->map.map[(int)floor(temp_pos.x)][(int)floor(temp_y)] == '8')
		c->player.pos.x = temp_pos.x;
}
