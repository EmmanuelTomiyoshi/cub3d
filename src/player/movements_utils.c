/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:40:19 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 12:44:07 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_temp_dir(t_map *map, t_cub3d *c)
{
	t_vector	temp_dir;

	temp_dir.x = 0;
	temp_dir.y = 0;
	if (c->key.move_left && !c->key.move_right)
	{
		temp_dir.x = map->player.dir.x;
		temp_dir.y = map->player.dir.y;
		rotate_vector(&temp_dir, 90);
	}
	if (c->key.move_right && !c->key.move_left)
	{
		temp_dir.x = map->player.dir.x;
		temp_dir.y = map->player.dir.y;
		rotate_vector(&temp_dir, 270);
	}
	return (temp_dir);
}
