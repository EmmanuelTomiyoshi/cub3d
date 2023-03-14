/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:49:56 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 23:14:31 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_button(t_button button, t_cub3d *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < button.width)
	{
		j = 0;
		while (j < button.height)
		{
			my_pixel_put(&c->mlx.img, i + button.x, j + button.y, RED_PANTONE);
			j++;
		}
		i++;
	}
	return (0);
}
// mlx_set_font(c->mlx.ptr, c->mlx.win.ptr, FONT_10X20);
// mlx_string_put(c->mlx.ptr,
//		c->mlx.win.ptr, button.x, button.y, color, "EXIT");

t_bool	clickable(t_button btn, int x, int y)
{
	if (x >= btn.x && x <= btn.x + btn.width && y >= btn.y && y <= btn.y + btn.height)
	{
		printf(YELLOW"is clickable\n"RESET);
		return (TRUE);
	}
	return (FALSE);
}

int	mouse_callback(int button, int x, int y, t_cub3d *c)
{
	if (button == LEFT_CLICK)
	{
		if (clickable(c->menu.fullscreen, x, y))
			draw_button(c->menu.fullscreen, c);
		else if (clickable(c->menu.crosshair, x, y))
			draw_button(c->menu.crosshair, c);
	}
	else if (button == MOUSE_RELEASE)
	{
		if (clickable(c->menu.fullscreen, x, y) || clickable(c->menu.crosshair, x, y))
			c->hovering = TRUE;
	}
	else
	{
		c->hovering = FALSE;
	}
	return (0);
}
