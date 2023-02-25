/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:55:39 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/25 05:21:19 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_error(char *one_line, t_cub3d *c, size_t number_player, size_t i)
{
	destroy_all(c);
	if (one_line[i] && !strchr("NSEW\n 01", one_line[i]))
	{
		free(one_line);
		exit_error(MSG_ERR_UNEXPECTED_CHAR, FALSE);
	}
	free(one_line);
	if (number_player == 0)
		exit_error(MSG_ERR_NO_PLAYER, FALSE);
	if (number_player == 2)
		exit_error(MSG_ERR_TWO_PLAYERS, FALSE);
}

void	verify_map_char(char *one_line, t_cub3d *c)
{
	size_t	i;
	size_t	number_player;

	i = 0;
	number_player = 0;
	while (one_line[i] && number_player <= 1 && \
		strchr("NSEW\n 01", one_line[i]))
	{
		if (strchr("NSEW", one_line[i]))
			number_player++;
		i++;
	}
	if ((one_line[i] && !strchr("NSEW\n 01", one_line[i])) || \
		number_player != 1)
		map_error(one_line, c, number_player, i);
}

void	init_map(t_cub3d *c, char *one_line)
{
	size_t	i;

	verify_map_char(one_line, c);
	c->map = ft_split(one_line, '\n');
	free(one_line);
	verify_map(c);
	i = 0;
	while (c->map[i])
	{
		printf("%s\n", c->map[i]);
		i++;
	}
}
