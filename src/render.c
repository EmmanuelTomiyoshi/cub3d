/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/23 01:58:37 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	improved_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr;
	dest += (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	fill_window(t_cub3d *c)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			improved_mlx_pixel_put(&(c->img), i, j, 0x0000020);
			i++;
		}
		j++;
	}
	mlx_set_font(c->mlx, c->win, "10x20");
	mlx_string_put(c->mlx, c->win, 200, 300, 0x0FFFF00, "FONT TEST");
	mlx_set_font(c->mlx, c->win, "7x13eurobold");
	mlx_string_put(c->mlx, c->win, 200, 600, 0x0FF00FF, "01234567890");
}

int	render(t_cub3d *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->img.image, 0, 0);
	fill_window(c);
	return (0);
}

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx);
	return (0);
}

void	loop(t_cub3d *c)
{
	mlx_hook(c->win, 17, 0, end_loop, c);
	mlx_expose_hook(c->win, &render, c);
	mlx_loop(c->mlx);
}
