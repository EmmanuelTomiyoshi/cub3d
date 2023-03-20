/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:34:49 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 00:35:05 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_level(t_cub3d *c)
{
	static int	i = 0;
	t_map		temp;

	if (i == c->level.count)
	{
		i = 0;
	}
	temp = c->map;
	c->map = c->level.name[i];
	c->level.name[i] = temp;
	i++;
}
