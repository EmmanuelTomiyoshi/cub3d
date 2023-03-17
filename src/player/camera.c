/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 17:34:29 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera(t_map *map, t_cub3d *c)
{
	if (c->key.look_left)
		look_left(map);
	if (c->key.look_right)
		look_right(map);
}

void	look_left(t_map *map)
{
	rotate_vector(&map->player.dir, map->player.camera.speed.x);
	rotate_vector(&map->player.camera.plane, map->player.camera.speed.x);
}

void	look_right(t_map *map)
{
	rotate_vector(&map->player.dir, map->player.camera.speed.y);
	rotate_vector(&map->player.camera.plane, map->player.camera.speed.y);
}
