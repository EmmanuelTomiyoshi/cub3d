/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:29:06 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/16 19:27:32 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_exposure(t_rgb fg, float opacity, t_rgb color)
{
	int	brightness;

	blend(fg, color, opacity, &color);
	brightness = sqrt(0.299 * pow(color.r, 2) + 0.587 * pow(color.g, 2)
			+ 0.114 * pow(color.b, 2));
	if (brightness < COLOR_THRESHOLD_MAX && brightness > COLOR_THRESHOLD_MIN)
		return (FALSE);
	return (TRUE);
}

int	brightness(t_cub3d *c)
{
	static int	light_floor;
	static int	light_ceiling;

	c->light_mode = !c->light_mode;

	if (c->light_mode == TRUE)
	{
		light_floor = c->map.f_color;
		light_ceiling = c->map.c_color;
		c->map.c_color = blending(c->map.c_color, ADD_LIGHT, c);
		c->map.f_color = blending(c->map.f_color, ADD_LIGHT, c);
	}
	else
	{
		c->map.c_color = light_ceiling;
		c->map.f_color = light_floor;
	}
	return (0);
}
