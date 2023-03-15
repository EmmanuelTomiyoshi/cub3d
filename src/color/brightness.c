/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:29:06 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/15 14:15:49 by etomiyos         ###   ########.fr       */
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

static void	update_color(t_rgb *object, int *color, float light, t_map *map)
{
	blend(map->foreground, *object, light, object);
	*color = get_rgb(object->r, object->g, object->b);
}

int	brightness(t_cub3d *c, int keycode)
{
	float	light;

	if (keycode == OPEN_BRACKET)
	{
		c->brightness -= 1;
		light = ADD_LIGHT;
	}
	else
	{
		c->brightness += 1;
		light = SUB_LIGHT;
	}
	c->exposure = check_exposure(c->map.foreground, light, c->map.floor);
	if (c->exposure == TRUE)
		return (0);
	else
		c->exposure = FALSE;
	printf("%u\n", c->brightness);
	//floor, ceiling, cubes
	update_color(&c->map.floor, &c->map.f_color, light, &c->map);
	update_color(&c->map.ceiling, &c->map.c_color, light, &c->map);
	update_color(&c->map.c_cube1, &c->map.cube1, light, &c->map);	//
	update_color(&c->map.c_cube2, &c->map.cube2, light, &c->map);	//
	return (0);
}
