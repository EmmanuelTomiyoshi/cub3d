/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/22 09:29:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/keysym.h>
#include <mlx.h>

void	improved_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr;
	dest += (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	move_left(t_cub3d *c)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			improved_mlx_pixel_put(&(c->img), i, j, 0x000F2B9);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(c->mlx, c->win, c->img.image, 0, 0);
	return (0);
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
			improved_mlx_pixel_put(&(c->img), i, j, 0x000B0B9);
			i++;
		}
		j++;
	}
}

int	render(t_cub3d *c)
{
	fill_window(c);
	mlx_hook(c->win, S_KEY, 0, move_left, c);
	mlx_put_image_to_window(c->mlx, c->win, c->img.image, 0, 0);
	return (0);
}
