/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:01 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 22:38:16 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	my_pixel_put(t_cub3d *c, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x <= c->mlx.win.width && y <= c->mlx.win.height && y >= 0 && x >= 0)
// 	{
// 		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + x
// 				* (c->mlx.img.bits_per_pixel) / 8);
// 		*(unsigned int *) dst = color;
// 	}
// }

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x <= WIDTH && y <= HEIGHT && y >= 0 && x >= 0)
	{
		dst = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
	}
}

int	get_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	if (r == 0 && b == 0 && g == 0)
		r = 1;
	if ((r > 255 || r < 0) || (b > 255 || b < 0) || (g > 255 || g < 0))
		return (0);
	rgb += (r & 0xFF) << 16;
	rgb += (g & 0xFF) << 8;
	rgb += (b & 0xFF);
	return (rgb);
}
