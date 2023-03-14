/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:49:56 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 11:58:58 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_btn_pos(t_button *btn, int x, int y)
{
	if (!btn)
		return ;
	btn->x = x;
	btn->y = y;
	if (btn->x)
		return ;
}

void	get_btn_size(t_button *btn, int width, int height)
{
	if (!btn)
		return ;
	btn->width = width;
	btn->height = height;
}

int	draw_button(t_button button, t_cub3d *c)
{
	int	i;
	int	j;
	int color;

	if (button.toggle)
		color = AQUA;
	else
		color = MARINE_BLUE;
	i = 0;
	while (i < button.width)
	{
		j = 0;
		while (j < button.height)
		{
			my_pixel_put(&c->menu.img, i + button.x, j + button.y, color);
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
		if (clickable(c->menu.fullscreen, x, y))
			c->menu.fullscreen.toggle = !c->menu.fullscreen.toggle;
		else if (clickable(c->menu.crosshair, x, y))
			c->menu.crosshair.toggle = !c->menu.crosshair.toggle;
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
