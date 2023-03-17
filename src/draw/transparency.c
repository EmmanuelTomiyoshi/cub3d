/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:06:40 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 12:07:21 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_argb	create_argb_color(int a, int r, int g, int b)
{
	t_argb	color;

	color.a = a & 0xFF;
	color.r = r & 0xFF;
	color.g = g & 0xFF;
	color.b = b & 0xFF;
	color.argb = (a << 24) | (r << 16) | (g << 8) | b;
	return (color);
}

t_argb	separate_argb_color(int argb)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (argb >> 24) & 0xFF;
	r = (argb >> 16) & 0xFF;
	g = (argb >> 8) & 0xFF;
	b = argb & 0xFF;
	return (create_argb_color(a, r, g, b));
}

t_argb	transparency(t_image *img, int x, int y)
{
	char	*pixel;
	int		argb[4];
	int		i;
	int		bytes;

	pixel = img->addr + (y * img->line_length + x * img->bits_per_pixel);
	if (x < 0 || x >= img->win_width || y < 0 || y >= img->win_height || !pixel)
		return (separate_argb_color(0));
	ft_memset(&argb, 0, 4);
	bytes = img->bits_per_pixel;
	i = 0;
	while (i < bytes)
	{
		if (img->endian)
			argb[4 - bytes + i] = pixel[i] & 0xFF;
		else
			argb[3 - i] = pixel[i] & 0xFF;
		++i;
	}
	return (create_argb_color(argb[0], argb[1], argb[2], argb[3]));
}
