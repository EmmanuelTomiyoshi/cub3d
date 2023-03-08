/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/07 13:14:21 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(char **argv, t_cub3d *c)
{
	c->map.map_file = ft_strdup(argv[1]);
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, WIN_NAME);
	c->img.image = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (c->mlx == NULL || c->win == NULL || c->img.image == NULL)
		exit_error(MSG_ERR_MLX_INIT, FALSE);
	c->img.addr = mlx_get_data_addr(c->img.image, &c->img.bits_per_pixel,
			&c->img.line_length, &c->img.endian);
	c->map.map = NULL;
	c->player = (t_player){0};
}
