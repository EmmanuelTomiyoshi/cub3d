/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:57:01 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/06 16:20:40 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_data(t_cub3d *c, int x, int y)
{
	verify_surrounding(c, NULL, x, y);
	c->player.pos.x = x + 0.5;
	c->player.pos.y = y + 0.5;
	c->player.dir.x = 0;
	c->player.dir.y = -1;
}
