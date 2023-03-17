/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 17:52:01 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_file(t_map *map, t_cub3d *c)
{
	char	*tmp;

	tmp = get_next_line(map->fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(map->fd);
	}
	if (c->temp.line)
		free(c->temp.line);
	if (map->file)
		ft_free_array(map->map);
	free(map->file);
}

void	destroy_coordinates(t_map *map)
{
	free(map->ea_path);
	free(map->we_path);
	free(map->no_path);
	free(map->so_path);
}

static void	destroy_map(t_cub3d *c)
{
	destroy_coordinates(&c->map);
	// ft_free_array(c->map.minimap.map);
	destroy_file(&c->map, c);
	close(c->map.fd);
}

static void	destroy_texture(t_image	tex, t_cub3d *c)
{
 	if (tex.ptr)
		mlx_destroy_image(c->mlx.ptr, tex.ptr);
}

static void	destroy_images(t_cub3d *c)
{
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.ptr);
	mlx_destroy_image(c->mlx.ptr, c->menu.img.ptr);
	if (c->menu.resize.ptr)
		mlx_destroy_image(c->mlx.ptr, c->menu.resize.ptr);
}

void	destroy_level_infos(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->level.count)
	{
		destroy_coordinates(&c->level.name[i]);
		destroy_file(&c->level.name[i], c);
		ft_free_array(c->level.name[i].map);
		if (c->level.name[i].minimap.map)
			ft_free_array(c->level.name[i].minimap.map);
		destroy_texture(c->level.name[i].ea_tex.img, c);
		destroy_texture(c->level.name[i].so_tex.img, c);
		destroy_texture(c->level.name[i].no_tex.img, c);
		destroy_texture(c->level.name[i].we_tex.img, c);
		i++;
	}
}

void	destroy_level(t_cub3d *c)
{
	destroy_level_infos(c);
	ft_free_array(c->level.files);
	free(c->level.name);
}

void	destroy_all(t_cub3d *c)
{
	destroy_images(c);
	destroy_map(c);
	// destroy_level(c);

	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	mlx_destroy_display(c->mlx.ptr);
	free(c->mlx.ptr);
}
