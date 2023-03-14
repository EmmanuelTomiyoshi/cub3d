/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:49:56 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 18:31:33 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "defines.h"

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
			change_win_size(c);
	}
	// else if (button == MOUSE_RELEASE)
	// {
	// 	if (clickable(c->menu.fullscreen, x, y))
	// 		c->hovering = TRUE;
	// }
	// else
	// {
	// 	c->hovering = FALSE;
	// }
	return (0);
}

int	change_win_size(t_cub3d *c)
{
	int	width;
	int	height;
	
	if (c->menu.fullscreen.toggle == TRUE)
	{
		width = c->mlx.screen_width;
		height = c->mlx.screen_height;	
	}
	else
	{
		width = WIDTH;
		height = HEIGHT;
	}
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.ptr);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	c->mlx.win.width = width;
	c->mlx.win.height = height;
	c->menu.img.win_width = width;
	c->menu.img.win_height = height;
	c->mlx.img.win_width = width;
	c->mlx.img.win_height = height;
	c->mlx.win.ptr = mlx_new_window(c->mlx.ptr,
			c->mlx.win.width,
			c->mlx.win.height,
			WIN_NAME);
	c->mlx.img.ptr = mlx_new_image(c->mlx.ptr,
			c->mlx.win.width,
			c->mlx.win.height);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.ptr,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);
	c->menu.fullscreen.toggle = !c->menu.fullscreen.toggle;
	loop(c);
	return (0);
}
