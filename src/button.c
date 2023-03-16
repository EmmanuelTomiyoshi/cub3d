/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:49:56 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/16 18:40:38 by etomiyos         ###   ########.fr       */
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
			temp = c->mlx.ea_tex;
			c->mlx.ea_tex = c->mlx.no_tex;
			c->mlx.no_tex = c->mlx.we_tex;
			c->mlx.we_tex = c->mlx.so_tex;
			c->mlx.so_tex = temp;
		}
		frame++;
	}
}

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

int	draw_button(t_button button, t_image img)
{
	int	i;
	int	j;
	int color;

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

void	resize_window(t_cub3d *c)
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

void	resize_menu(t_cub3d *c)
{
	int					x;
	int					y;
	int					sqrx;
	int					sqry;
	unsigned int		color;

	x = 0;
	c->menu.width_ratio = (float) c->mlx.img.win_width / c->menu.img.win_width;
	c->menu.height_ratio = (float) c->mlx.img.win_height / c->menu.img.win_height;
	get_btn_pos(&c->menu.quit, (int)(c->menu.quit.x * c->menu.width_ratio), (int)(c->menu.quit.y * c->menu.height_ratio));
	get_btn_size(&c->menu.quit, (int)(c->menu.quit.width * c->menu.width_ratio), (int)(c->menu.quit.height * c->menu.height_ratio));
	while (x < c->menu.img.win_width)
	{
		y = 0;
		while (y < c->menu.img.win_height)
		{
			color = *(unsigned int *)(c->menu.img.addr + \
					(y * c->menu.img.line_length + x * (c->menu.img.bits_per_pixel) / 8));
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

int	change_win_size(t_cub3d *c)
{
	int	width;
	int	height;

	c->menu.fullscreen.toggle = !c->menu.fullscreen.toggle;
	if (c->menu.fullscreen.toggle == TRUE)
	{
		width = c->mlx.screen_width;
		height = c->mlx.screen_height;
		if (!c->menu.resize.ptr)
		{
			c->menu.resize.ptr = mlx_new_image(c->mlx.ptr, width, height);
			c->menu.resize.addr = mlx_get_data_addr(c->menu.resize.ptr,
					&c->menu.resize.bits_per_pixel, &c->menu.resize.line_length,
					&c->menu.resize.endian);
		}
	}
	else
	{
		width = WIDTH;
		height = HEIGHT;
	}
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.ptr);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);

	//novo tamanho da janela
	c->mlx.win.width = width;
	c->mlx.win.height = height;
	//novo tamanho da imagem do menu
	c->menu.resize.win_width = width;
	c->menu.resize.win_height = height;
	//novo tamanho da imagem da mlx
	c->mlx.img.win_width = width;
	c->mlx.img.win_height = height;

	//criando a nova janela
	resize_window(c);
	resize_menu(c);
	loop(c);
	return (0);
}
