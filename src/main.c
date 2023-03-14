/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 18:02:16 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	test_texture()
{
	t_mlx	mlx;
	int		width;
	int		height;

	width = 0;
	height = 0;
	mlx.ptr = mlx_init();
	mlx.win.ptr = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	mlx.img.image = mlx_xpm_file_to_image(mlx.ptr, "./src/textures/stone01.xpm", &width, &height);
	printf("%d\n", width);
	mlx.img.addr = mlx_get_data_addr(mlx.img.image, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx_put_image_to_window(mlx.ptr, mlx.win.ptr, mlx.img.image, 0, 0);
	mlx_loop(mlx.ptr);
}*/

void	init_texture(t_cub3d *c)
{
	c->mlx.ea_tex.img.image = mlx_xpm_file_to_image(c->mlx.ptr, \
		c->map.ea_path, &c->mlx.ea_tex.width, &c->mlx.ea_tex.height);
	c->mlx.ea_tex.img.addr = \
		mlx_get_data_addr(c->mlx.ea_tex.img.image, \
			&c->mlx.ea_tex.img.bits_per_pixel, \
			&c->mlx.ea_tex.img.line_length, &c->mlx.ea_tex.img.endian);
	c->mlx.no_tex.img.image = mlx_xpm_file_to_image(c->mlx.ptr, \
		c->map.no_path, &c->mlx.no_tex.width, &c->mlx.no_tex.height);
	c->mlx.no_tex.img.addr = \
		mlx_get_data_addr(c->mlx.no_tex.img.image, \
			&c->mlx.no_tex.img.bits_per_pixel, \
			&c->mlx.no_tex.img.line_length, &c->mlx.no_tex.img.endian);
	c->mlx.so_tex.img.image = mlx_xpm_file_to_image(c->mlx.ptr, \
		c->map.so_path, &c->mlx.so_tex.width, &c->mlx.so_tex.height);
	c->mlx.so_tex.img.addr = \
		mlx_get_data_addr(c->mlx.so_tex.img.image, \
			&c->mlx.so_tex.img.bits_per_pixel, \
			&c->mlx.so_tex.img.line_length, &c->mlx.so_tex.img.endian);
	c->mlx.we_tex.img.image = mlx_xpm_file_to_image(c->mlx.ptr, \
		c->map.we_path, &c->mlx.we_tex.width, &c->mlx.we_tex.height);
	c->mlx.we_tex.img.addr = \
		mlx_get_data_addr(c->mlx.we_tex.img.image, \
			&c->mlx.we_tex.img.bits_per_pixel, \
			&c->mlx.we_tex.img.line_length, &c->mlx.we_tex.img.endian);
}

int	main(int argc, char **argv)
{
	t_cub3d		cub3d;

	invalid_args(&cub3d, argc, argv);
	init(argv, &cub3d);
	get_data(&cub3d);
	init_texture(&cub3d);
	loop(&cub3d);
	destroy_all(&cub3d);
	return (EXIT_SUCCESS);
}
