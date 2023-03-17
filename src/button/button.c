/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:49:56 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 20:53:04 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	animate_sprite(t_cub3d *c)
{
	static int	frame = 0;
	t_texture	temp;

	if (c->animate == TRUE)
	{
		if (frame % 60 == 0)
		{
			temp = c->map.ea_tex;
			c->map.ea_tex = c->map.no_tex;
			c->map.no_tex = c->map.we_tex;
			c->map.we_tex = c->map.so_tex;
			c->map.so_tex = temp;
		}
		frame++;
	}
}

int	draw_button(t_button button, t_image img)
{
	int	i;
	int	j;
	int	color;

	if (button.toggle)
		color = MARINE_BLUE;
	else
		color = AQUA;
	i = 0;
	while (i < button.width)
	{
		j = 0;
		while (j < button.height)
		{
			my_pixel_put(&img, i + button.x, j + button.y, color);
			j++;
		}
		i++;
	}
	return (0);
}

t_bool	clickable(t_button btn, int x, int y)
{
	if (x >= btn.x && x <= btn.x + btn.width)
	{
		if (y >= btn.y && y <= btn.y + btn.height)
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

int	mouse_callback(int button, int x, int y, t_cub3d *c)
{
	if (button == LEFT_CLICK)
	{
		if (clickable(c->menu.quit, x, y))
			end_loop(c);
	}
	return (0);
}
