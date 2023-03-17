/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:00:15 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 17:39:22 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movements(t_map *map, t_cub3d *c)
{
	if (c->key.run)
		player_speed(c);
	if (c->key.move_backwards)
		walk_backwards(map, c);
	if (c->key.move_foward)
		walk_forward(map, c);
	if (c->key.move_left)
		walk_left(map, c);
	if (c->key.move_right)
		walk_right(map, c);
}

void	walk_left(t_map *map, t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = map->player.dir.x;
	temp_dir.y = map->player.dir.y;
	rotate_vector(&temp_dir, 90);
	temp_pos.x = map->player.pos.x + temp_dir.x * c->key.speed;
	temp_pos.y = map->player.pos.y + temp_dir.y * c->key.speed;
	temp_y = map->player.pos.y;
	if (map->map[(int)floor(map->player.pos.x)][(int)floor(temp_pos.y + \
		temp_dir.y * 0.15)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		temp_dir.x * 0.15)][(int)floor(temp_y)] == '8')
		map->player.pos.x = temp_pos.x;
}

void	walk_forward(t_map *map, t_cub3d *c)
{
	t_vector	temp_pos;
	double		temp_y;

	temp_pos.x = map->player.pos.x + map->player.dir.x * c->key.speed;
	temp_pos.y = map->player.pos.y + map->player.dir.y * c->key.speed;
	temp_y = map->player.pos.y;
	if (map->map[(int)floor(map->player.pos.x)][(int)floor(temp_pos.y + \
		map->player.dir.y * 0.15)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		map->player.dir.x * 0.15)][(int)floor(temp_y)] == '8')
		map->player.pos.x = temp_pos.x;
}

void	walk_backwards(t_map *map, t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = map->player.dir.x;
	temp_dir.y = map->player.dir.y;
	rotate_vector(&temp_dir, 180);
	temp_pos.x = map->player.pos.x + temp_dir.x * c->key.speed;
	temp_pos.y = map->player.pos.y + temp_dir.y * c->key.speed;
	temp_y = map->player.pos.y;
	if (map->map[(int)floor(map->player.pos.x)][(int)floor(temp_pos.y + \
		temp_dir.y * 0.15)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		temp_dir.x * 0.15)][(int)floor(temp_y)] == '8')
		map->player.pos.x = temp_pos.x;
}

void	walk_right(t_map *map, t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = map->player.dir.x;
	temp_dir.y = map->player.dir.y;
	rotate_vector(&temp_dir, 270);
	temp_pos.x = map->player.pos.x + temp_dir.x * c->key.speed;
	temp_pos.y = map->player.pos.y + temp_dir.y * c->key.speed;
	temp_y = map->player.pos.y;
	if (map->map[(int)floor(map->player.pos.x)][(int)floor(temp_pos.y
			+ temp_dir.y * 0.15)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		temp_dir.x * 0.15)][(int)floor(temp_y)] == '8')
		map->player.pos.x = temp_pos.x;
}
