/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:01 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 00:32:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	blend(t_rgb fg, t_rgb bg, float opacity, t_rgb *result)
{
	result->r = fg.r * opacity + bg.r * (1 - opacity);
	result->g = fg.g * opacity + bg.g * (1 - opacity);
	result->b = fg.b * opacity + bg.b * (1 - opacity);
}

void	apply_night_filter(t_rgb *color)
{
	color->r *= 0.6;
	color->g *= 0.6;
	color->b *= 1.2;
}

unsigned int	blending(unsigned int color, float opacity, t_cub3d *c)
{
	t_rgb	rgb;

	itorgb((int)color, &rgb);
	rgb.r = 0 * opacity + rgb.r * (1 - opacity);
	rgb.g = 0 * opacity + rgb.g * (1 - opacity);
	rgb.b = 0 * opacity + rgb.b * (1 - opacity);
	if (c->state.light_mode == TRUE)
		apply_night_filter(&rgb);
	return ((unsigned int) get_rgb(rgb.r, rgb.g, rgb.b));
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
