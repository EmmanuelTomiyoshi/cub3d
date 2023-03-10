/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/09 18:32:22 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			improved_mlx_pixel_put(&(c->mlx.img), i, j, 0x0000020);
			i++;
		}
		j++;
	}
	mlx_set_font(c->mlx.ptr, c->mlx.win, "10x20");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 200, 300, 0x0FFFF00, "FONT TEST");
	mlx_set_font(c->mlx.ptr, c->mlx.win, "7x13eurobold");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 200, 600, 0x0FF00FF, "01234567890");
}

int	render(t_cub3d *c)
{
	mlx_put_image_to_window(c->mlx.ptr, c->mlx.win, c->mlx.img.image, 0, 0);
	fill_window(c);
	return (0);
}

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx.ptr);
	return (0);
}

void	loop(t_cub3d *c)
{
	mlx_hook(c->mlx.win, 17, 0, end_loop, c);
	mlx_expose_hook(c->mlx.win, &draw, c);
	mlx_loop(c->mlx.ptr);
}
