/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:00:15 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 13:45:10 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movements(t_map *map, t_cub3d *c)
{
	if (c->key.run)
		player_speed(c);
	if (c->key.move_backwards && !c->key.move_forward)
		walk_backwards(map, c);
	if (c->key.move_forward && !c->key.move_backwards)
		walk_forward(map, c);
	if ((!c->key.move_backwards && !c->key.move_forward)
		|| (c->key.move_backwards && c->key.move_forward))
	{
		if (c->key.move_left)
			walk_left(map, c);
		if (c->key.move_right)
			walk_right(map, c);
	}
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
		temp_dir.y * c->key.speed * 3)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		temp_dir.x * c->key.speed * 3)][(int)floor(temp_y)] == '8')
		map->player.pos.x = temp_pos.x;
}

void	walk_forward(t_map *map, t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir = get_temp_dir(map, c);
	temp_dir.x = temp_dir.x * c->key.speed + map->player.dir.x * c->key.speed;
	temp_dir.y = temp_dir.y * c->key.speed + map->player.dir.y * c->key.speed;
	temp_pos.x = map->player.pos.x + temp_dir.x;
	temp_pos.y = map->player.pos.y + temp_dir.y;
	temp_y = map->player.pos.y;
	if (map->map[(int)floor(map->player.pos.x)][(int)floor(temp_pos.y + \
		temp_dir.y * 3)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		temp_dir.x * 3)][(int)floor(temp_y)] == '8')
		map->player.pos.x = temp_pos.x;
}

void	walk_backwards(t_map *map, t_cub3d *c)
{
	t_vector	temp_dir;
	t_vector	temp_dir2;
	t_vector	temp_pos;
	double		temp_y;

	temp_dir.x = map->player.dir.x;
	temp_dir.y = map->player.dir.y;
	rotate_vector(&temp_dir, 180);
	temp_dir2 = get_temp_dir(map, c);
	temp_dir.x = temp_dir.x * c->key.speed + temp_dir2.x * c->key.speed;
	temp_dir.y = temp_dir.y * c->key.speed + temp_dir2.y * c->key.speed;
	temp_pos.x = map->player.pos.x + temp_dir.x;
	temp_pos.y = map->player.pos.y + temp_dir.y;
	temp_y = map->player.pos.y;
	if (map->map[(int)floor(map->player.pos.x)][(int)floor(temp_pos.y + \
		temp_dir.y * c->key.speed * 3)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		temp_dir.x * c->key.speed * 3)][(int)floor(temp_y)] == '8')
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
			+ temp_dir.y * c->key.speed * 3)] == '8')
		map->player.pos.y = temp_pos.y;
	if (map->map[(int)floor(temp_pos.x + \
		temp_dir.x * c->key.speed * 3)][(int)floor(temp_y)] == '8')
		map->player.pos.x = temp_pos.x;
}
