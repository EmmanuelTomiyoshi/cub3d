/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:35:23 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 17:02:51 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse(int x, int y, t_cub3d *c)
{
	static int	prev = 0;

	(void)y;
	if (!c->menu.active)
	{
		if (x < prev)
			look_left(&c->map);
		else if (x > prev)
			look_right(&c->map);
		prev = x;
	}
	else
		prev = x;
	return (0);
}
