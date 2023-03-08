/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:01 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/08 20:11:57 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_cub3d *c, int x, int y, int color)
{
	char	*dst;

	if (x <= WIDTH && y <= HEIGHT && y >= 0 && x >= 0)
	{
		dst = c->mlx.img.addr + (y * c->mlx.img.line_length + x
				* (c->mlx.img.bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
	}
}

void	improved_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr;
	dest += (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
