/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:56:46 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 18:54:31 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verify_up(t_map *map, size_t i, size_t j, t_cub3d *c)
{
	if (verify_char(map, i + 1, j))
	{
		destroy_all(c);
		exit_error(MSG_ERR_MAP_BORDER, FALSE);
	}
}

t_bool	verify_char(t_map *map, size_t i, size_t j)
{
	size_t	m;

	m = ft_strlen(map->map[i]);
	if (m <= j - 1)
		return (TRUE);
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

void	verify_surrounding(t_map *map, t_cub3d *c, size_t i, size_t j)
{
	size_t	n;

	n = count_lines(map);
	if ((i == n) || (i == 0))
	{
		destroy_all(c);
		exit_error(MSG_ERR_MAP_BORDER, FALSE);
	}
	if (verify_char(map, i, j))
	{
		destroy_all(c);
		exit_error(MSG_ERR_MAP_BORDER, FALSE);
	}
	if (i < n)
		verify_up(map, i, j, c);
	if (i > 0)
	{
		if (verify_char(map, i - 1, j))
		{
			destroy_all(c);
			exit_error(MSG_ERR_MAP_BORDER, FALSE);
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
				verify_surrounding(map, c, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}
