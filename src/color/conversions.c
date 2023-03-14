/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:22:10 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 01:37:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	itorgb(int color, t_rgb *result)
{
	result->r = (color >> 16) & 0xFF;
	result->g = (color >> 8) & 0xFF;
	result->b = color & 0xFF;
}

void	blend(t_rgb fg, t_rgb bg, float opacity, t_rgb *result)
{
	result->r = fg.r * opacity + bg.r * (1 - opacity);
	result->g = fg.g * opacity + bg.g * (1 - opacity);
	result->b = fg.b * opacity + bg.b * (1 - opacity);
}

void	alpha_blending(t_cub3d *c)
{
	t_rgb	fg;
	t_rgb	bg;
	t_rgb	result;

	(void)c;
	fg.r = 255;
	fg.g = 0;
	fg.b = 0;
	bg.r = 255;
	bg.g = 255;
	bg.b = 255;
	blend(fg, bg, 0.5, &result);
	printf("Resulting color: (%d, %d, %d)\n", result.r, result.g, result.b);
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
