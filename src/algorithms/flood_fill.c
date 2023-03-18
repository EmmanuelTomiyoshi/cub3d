/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:56:46 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/18 10:00:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_queue	*verify_line(t_map *map, size_t i, size_t j, t_cub3d *c)
{
	size_t	m;

	m = strlen(map->map[i]);
	if (m >= j - 1)
	{
		c->f_queue = queue_put(j - 1, i, c);
		if (m >= j)
		{
			c->f_queue = queue_put(j, i, c);
			if (m >= j + 1)
				c->f_queue = queue_put(j + 1, i, c);
		}
	}
	return (c->f_queue);
}

t_bool	verify_char(t_map *map, size_t i, size_t j)
{
	size_t	m;

	m = strlen(map->map[i]);
	if (m >= j - 1)
	{
		if (!ft_strchr("018ENWS", map->map[i][j - 1]))
			return (TRUE);
		if (m >= j)
		{
			if (!ft_strchr("018ENWS", map->map[i][j]))
				return (TRUE);
			if (m >= j + 1)
			{
				if (!ft_strchr("018ENWS", map->map[i][j + 1]))
					return (TRUE);
				if (!map->map[i][j + 1])
					return (TRUE);
			}
		}
	}
	return (FALSE);
}

void	verify_surrounding(t_map *map, t_cub3d *c, t_queue *queue,
			size_t i, size_t j)
{
	size_t	n;

	n = count_lines(map);
	if (verify_char(map, i, j))
	{
		if (queue)
			queue_clear(queue);
		destroy_all(c);
		exit_error(MSG_ERR_MAP_BORDER, FALSE);
	}
	if (i < n)
		verify_up(map, queue, i, j, c);
	if (i > 0)
	{
		if (verify_char(map, i - 1, j))
		{
			if (queue)
				queue_clear(queue);
			destroy_all(c);
			exit_error(MSG_ERR_MAP_BORDER, FALSE);
		}
	}
}

void	flood_fill(t_map *map, t_cub3d *c, size_t i, size_t j)
{
	size_t	n;
	size_t	temp_i;
	size_t	temp_j;

	n = count_lines(map);
	c->f_queue = NULL;
	c->f_queue = queue_put(j, i, c);
	while (queue_empty(c->f_queue))
	{
		c->f_queue = queue_get(&temp_j, &temp_i, c);
		if (map->map[temp_i][temp_j] == '0')
		{
			verify_surrounding(map, c, c->f_queue, temp_i, temp_j);
			map->map[temp_i][temp_j] = '8';
			c->f_queue = verify_line(map, temp_i, temp_j, c);
			if (temp_i < n)
				c->f_queue = verify_line(map, temp_i + 1, temp_j, c);
			if (temp_i > 0)
				c->f_queue = verify_line(map, temp_i - 1, temp_j, c);
		}
	}
}

void	verify_map(t_map *map, t_cub3d *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (strchr("NESW", map->map[i][j]))
				get_player_data(map, c, i, j);
			if (map->map[i][j] == '0')
				flood_fill(map, c, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}
