/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 23:30:19 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_map *map, t_cub3d *c)
{
	map->ea_tex.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr, \
		map->ea_path, &map->ea_tex.width, &map->ea_tex.height);
	map->ea_tex.img.addr = \
		mlx_get_data_addr(map->ea_tex.img.ptr, \
			&map->ea_tex.img.bits_per_pixel, \
			&map->ea_tex.img.line_length, &map->ea_tex.img.endian);
	map->no_tex.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr, \
		map->no_path, &map->no_tex.width, &map->no_tex.height);
	map->no_tex.img.addr = \
		mlx_get_data_addr(map->no_tex.img.ptr, \
			&map->no_tex.img.bits_per_pixel, \
			&map->no_tex.img.line_length, &map->no_tex.img.endian);
	map->so_tex.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr, \
		map->so_path, &map->so_tex.width, &map->so_tex.height);
	map->so_tex.img.addr = \
		mlx_get_data_addr(map->so_tex.img.ptr, \
			&map->so_tex.img.bits_per_pixel, \
			&map->so_tex.img.line_length, &map->so_tex.img.endian);
	map->we_tex.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr, \
		map->we_path, &map->we_tex.width, &map->we_tex.height);
	map->we_tex.img.addr = \
		mlx_get_data_addr(map->we_tex.img.ptr, \
			&map->we_tex.img.bits_per_pixel, \
			&map->we_tex.img.line_length, &map->we_tex.img.endian);
}

int	main(int argc, char **argv)
{
	t_cub3d		cub3d;

	invalid_args(argc, argv, &cub3d);
	init(argv, &cub3d);
	get_data(&cub3d);
	init_minimap(&cub3d.map);
	get_texture(&cub3d.map, &cub3d);
	get_level_info(&cub3d);
	loop(&cub3d);
	destroy_all(&cub3d);
	return (EXIT_SUCCESS);
}
