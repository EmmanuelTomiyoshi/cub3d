/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:29:06 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/16 15:35:40 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "defines.h"

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

// static void	update_color(t_rgb *object, int *color, float light, t_map *map)
// {
// 	blend(map->foreground, *object, light, object);
// 	*color = get_rgb(object->r, object->g, object->b);
// }

int	brightness(t_cub3d *c)
{
	static int	light_floor;
	static int	light_ceiling;

	c->light_mode = !c->light_mode;

	if (c->light_mode == TRUE)
	{
		light_floor = c->map.f_color;
		light_ceiling = c->map.c_color;
		c->map.c_color = blending(c->map.c_color, ADD_LIGHT);
		c->map.f_color = blending(c->map.f_color, ADD_LIGHT);
	}
	else
	{
		c->map.c_color = light_ceiling;
		c->map.f_color = light_floor;
	}

	printf("%d | %d\n", c->map.c_color, c->map.f_color);
	return (0);
}
