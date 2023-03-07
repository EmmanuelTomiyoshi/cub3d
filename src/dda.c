/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:48:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/07 17:02:30 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	background(t_cub3d *c)
{
	t_point	point1;
	t_point	point2;

	point1.x = 0;
	point1.y = 0;
	point2.x = WIDTH;
	point2.y = 0;
	while (point1.y <= HEIGHT)
	{
		if (point1.y <= HEIGHT / 2)
			bresenham(&point1, &point2, c, c->file_data->c_color);
		else
			bresenham(&point1, &point2, c, c->file_data->f_color);
		point1.y++;
		point2.y++;
	}
}

int	draw(t_cub3d *c)
{
	background(c);
	mlx_put_image_to_window(c->mlx, c->win, c->img.image, 0, 0);
	return (0);
}
