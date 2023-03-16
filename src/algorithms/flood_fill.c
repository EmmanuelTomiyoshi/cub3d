/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:56:46 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/16 16:03:41 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_queue	*verify_line(t_queue *f_queue, size_t i, t_cub3d *c, size_t j)
{
	size_t	m;

	m = strlen(c->map.map[i]);
	if (m >= j - 1)
	{
		f_queue = queue_put(f_queue, j - 1, i);
		if (m >= j)
		{
			f_queue = queue_put(f_queue, j, i);
			if (m >= j + 1)
				f_queue = queue_put(f_queue, j + 1, i);
		}
	}
	return (f_queue);
}

t_bool	verify_char(t_cub3d *c, size_t i, size_t j)
{
	size_t	m;

	m = strlen(c->map.map[i]);
	if (m >= j - 1)
	{
		if (!ft_strchr("018ENWS", c->map.map[i][j - 1]))
			return (TRUE);
		if (m >= j)
		{
			if (!ft_strchr("018ENWS", c->map.map[i][j]))
				return (TRUE);
			if (m >= j + 1)
			{
				if (!ft_strchr("018ENWS", c->map.map[i][j + 1]))
					return (TRUE);
				if (!c->map.map[i][j + 1])
					return (TRUE);
			}
		}
	}
	return (FALSE);
}

void	verify_surrounding(t_cub3d *c, t_queue *queue, size_t i, size_t j)
{
	size_t	n;

	n = count_lines(c);
	if (verify_char (c, i, j))
	{
		if (queue)
			queue_clear(queue);
		destroy_all(c);
		exit_error(MSG_ERR_MAP_BORDER, FALSE);
	}
	if (i < n)
		verify_up(queue, i, j, c);
	if (i > 0)
	{
		if (verify_char (c, i - 1, j))
		{
			if (queue)
				queue_clear(queue);
			destroy_all(c);
			exit_error(MSG_ERR_MAP_BORDER, FALSE);
		}
	}
}

void	flood_fill(t_cub3d *c, size_t n, size_t i, size_t j)
{
	t_queue	*f_queue;
	size_t	temp_i;
	size_t	temp_j;

	f_queue = NULL;
	f_queue = queue_put(f_queue, j, i);
	while (queue_empty(f_queue))
	{
		f_queue = queue_get(f_queue, &temp_j, &temp_i);
		if (c->map.map[temp_i][temp_j] == '0')
		{
			verify_surrounding(c, f_queue, temp_i, temp_j);
			c->map.map[temp_i][temp_j] = '8';
			f_queue = verify_line (f_queue, temp_i, c, temp_j);
			if (temp_i < n)
				f_queue = verify_line (f_queue, temp_i + 1, c, temp_j);
			if (temp_i > 0)
				f_queue = verify_line (f_queue, temp_i - 1, c, temp_j);
		}
	}
}

void	verify_map(t_cub3d *c)
{
	size_t	n;
	size_t	i;
	size_t	j;

	n = count_lines(c);
	i = 0;
	j = 0;
	while (c->map.map[i])
	{
		while (c->map.map[i][j])
		{
			if (strchr("NESW", c->map.map[i][j]))
				get_player_data(c, i, j);
			if (c->map.map[i][j] == '0')
				flood_fill(c, n, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}
