/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:09:50 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 20:18:38 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_level_fd(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->level.count)
	{
		c->level.temp = ft_strjoin("assets/maps/", c->level.files[i]);
		c->level.name[i].fd = open(c->level.temp, O_RDONLY);
		if (c->level.name[i].fd == -1)
		{
			free(c->level.temp);
			destroy_level(c);
			exit_error(MSG_ERR_LEVEL_FILE, TRUE);
		}
		free(c->level.temp);
		i++;
	}
}

void	get_level_colors_and_coordinates(t_cub3d *c)
{
	int		i;
	char	*one_line;

	i = 0;
	while (i < c->level.count)
	{
		get_colors_and_coordinates(&c->level.name[i], c);
		get_map_content(&c->level.name[i], &one_line, c);
		get_map(&c->level.name[i], c, one_line);
		get_minimap(&c->level.name[i]);
		get_texture(&c->level.name[i], c);
		i++;
	}
}
