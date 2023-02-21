/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 12:11:48 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub3d *c)
{
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "cub3d");
	c->img.image = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->img.addr = mlx_get_data_addr(c->img.image, &c->img.bits_per_pixel,
			&c->img.line_length, &c->img.endian);
}
