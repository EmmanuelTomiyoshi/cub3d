/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:55:39 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/15 00:15:31 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_error(char *one_line, size_t nbr_player, size_t i, t_cub3d *c)
{
	destroy_all(c);
	if (one_line[i] && !strchr("NSEW\n 01", one_line[i]))
	{
		free(one_line);
		exit_error(MSG_ERR_UNEXPECTED_CHAR, FALSE);
	}
	free(one_line);
	if (nbr_player == 0)
		exit_error(MSG_ERR_NO_PLAYER, FALSE);
	if (nbr_player == 2)
		exit_error(MSG_ERR_TWO_PLAYERS, FALSE);
}

static void	verify_map_char(char *one_line, t_cub3d *c)
{
	size_t	i;
	size_t	nbr_player;

	i = 0;
	nbr_player = 0;
	while (one_line[i] && nbr_player <= 1 && \
		strchr("NSEW\n 01", one_line[i]))
	{
		if (strchr("NSEW", one_line[i]))
			nbr_player++;
		i++;
	}
	if ((one_line[i] && !strchr("NSEW\n 01", one_line[i])) || \
		nbr_player != 1)
		map_error(one_line, nbr_player, i, c);
}

void	init_map(t_cub3d *c, char *one_line)
{
	size_t	i;

	verify_map_char(one_line, c);
	c->map.map = ft_split(one_line, '\n');
	free(one_line);
	verify_map(c);
	i = 0;
	while (c->map.map[i])
		i++;
}
