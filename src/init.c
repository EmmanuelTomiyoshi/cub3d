/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/12 23:26:43 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_square_colors(t_cub3d *c)
{
	itorgb(DARK_BLUE, &c->map.c_cube1);
	itorgb(LIGHT_BLUE, &c->map.c_cube2);
	c->map.cube1 = DARK_BLUE;
	c->map.cube2 = LIGHT_BLUE;
}

void	init(char **argv, t_cub3d *c)
{
	c->map.file = ft_strdup(argv[1]);
	c->mlx.ptr = mlx_init();
	c->mlx.win.ptr = mlx_new_window(c->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	c->mlx.img.image = mlx_new_image(c->mlx.ptr, WIDTH, HEIGHT);
	if (c->mlx.ptr == NULL || c->mlx.win.ptr == NULL || c->mlx.img.image == NULL)
		exit_error(MSG_ERR_MLX_INIT, FALSE);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.image,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);
	c->map.map = NULL;
	c->dda.pixel = 0;
	c->mlx.win.width = WIDTH;
	c->mlx.win.height = HEIGHT;
	c->player = (t_player){0};
	init_square_colors(c);
	mlx_get_screen_size(c->mlx.ptr, &c->mlx.screen_width, &c->mlx.screen_height);
}
