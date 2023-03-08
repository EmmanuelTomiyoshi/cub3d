/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/08 20:11:51 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(char **argv, t_cub3d *c)
{
	c->map.file = ft_strdup(argv[1]);
	c->mlx.ptr = mlx_init();
	c->mlx.win = mlx_new_window(c->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	c->mlx.img.image = mlx_new_image(c->mlx.ptr, WIDTH, HEIGHT);
	if (c->mlx.ptr == NULL || c->mlx.win == NULL || c->mlx.img.image == NULL)
		exit_error(MSG_ERR_MLX_INIT, FALSE);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.image,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);
	c->map.map = NULL;
	c->dist.pixel = 0;
	c->player = (t_player){0};
}
