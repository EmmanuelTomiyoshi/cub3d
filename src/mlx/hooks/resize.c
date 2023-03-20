/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:15:35 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/20 11:27:46 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	resize_window(t_cub3d *c)
{
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
}

static void	resize_count(t_cub3d *c, int x, int y)
{
	int					sqrx;
	int					sqry;
	unsigned int		color;

	while (x < c->menu.img.width)
	{
		y = 0;
		while (y < c->menu.img.height)
		{
			color = return_color(&c->menu.img, x, y);
			sqrx = x * c->menu.width_ratio;
			while (sqrx < x * c->menu.width_ratio + c->menu.width_ratio)
			{
				sqry = y * c->menu.height_ratio;
				while (sqry < y * c->menu.height_ratio + c->menu.height_ratio)
				{
					my_pixel_put(&c->menu.resize, sqrx, sqry, color);
					sqry++;
				}
				sqrx++;
			}
			y++;
		}
		x++;
	}
}

static void	resize_menu(t_cub3d *c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	c->menu.width_ratio = (float) c->mlx.img.width / c->menu.img.width;
	c->menu.height_ratio = (float) c->mlx.img.height \
		/ c->menu.img.height;
	get_btn_pos(&c->menu.quit, (int)(c->menu.quit.x * c->menu.width_ratio), \
		(int)(c->menu.quit.y * c->menu.height_ratio));
	get_btn_size(&c->menu.quit, (int)(c->menu.quit.width * \
		c->menu.width_ratio), \
		(int)(c->menu.quit.height * c->menu.height_ratio));
	resize_count(c, x, y);
}

static void	get_width_and_height(t_cub3d *c, int *width, int *height)
{
	if (c->menu.fullscreen.toggle == TRUE)
	{
		*width = c->mlx.screen_width;
		*height = c->mlx.screen_height;
		if (!c->menu.resize.ptr)
		{
			c->menu.resize.ptr = mlx_new_image(c->mlx.ptr, *width, *height);
			c->menu.resize.addr = mlx_get_data_addr(c->menu.resize.ptr,
					&c->menu.resize.bits_per_pixel, &c->menu.resize.line_length,
					&c->menu.resize.endian);
		}
	}
	else
	{
		*width = WIDTH;
		*height = HEIGHT;
	}
}

int	change_win_size(t_cub3d *c)
{
	int	width;
	int	height;

	c->menu.fullscreen.toggle = !c->menu.fullscreen.toggle;
	get_width_and_height(c, &width, &height);
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.ptr);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	c->mlx.win.width = width;
	c->mlx.win.height = height;
	c->menu.resize.width = width;
	c->menu.resize.height = height;
	c->mlx.img.width = width;
	c->mlx.img.height = height;
	resize_window(c);
	resize_menu(c);
	loop(c);
	return (0);
}
