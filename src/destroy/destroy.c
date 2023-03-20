/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 15:30:16 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_coordinates(t_map *map)
{
	free(map->ea_path);
	free(map->we_path);
	free(map->no_path);
	free(map->so_path);
}

void	destroy_texture(t_image	tex, t_cub3d *c)
{
	if (tex.ptr)
		mlx_destroy_image(c->mlx.ptr, tex.ptr);
}

static void	destroy_map(t_cub3d *c)
{
	destroy_coordinates(&c->map);
	destroy_file(&c->map, c);
	destroy_texture(c->map.ea_tex.img, c);
	destroy_texture(c->map.so_tex.img, c);
	destroy_texture(c->map.no_tex.img, c);
	destroy_texture(c->map.we_tex.img, c);
	if (c->level.count != 0)
		ft_free_array(c->map.minimap.map);
	close(c->map.fd);
	ft_free_array(c->map.map);
}

static void	destroy_images(t_cub3d *c)
{
	if (c->mlx.img.ptr)
		mlx_destroy_image(c->mlx.ptr, c->mlx.img.ptr);
	if (c->menu.img.ptr)
		mlx_destroy_image(c->mlx.ptr, c->menu.img.ptr);
	if (c->menu.resize.ptr)
		mlx_destroy_image(c->mlx.ptr, c->menu.resize.ptr);
}

void	destroy_all(t_cub3d *c)
{
	destroy_images(c);
	destroy_map(c);
	destroy_level(c);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	mlx_destroy_display(c->mlx.ptr);
	free(c->mlx.ptr);
}
