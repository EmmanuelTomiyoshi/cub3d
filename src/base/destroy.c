/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 11:10:03 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_file(t_cub3d *c)
{
	char	*tmp;

	tmp = get_next_line(c->map.fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(c->map.fd);
	}
	if (c->temp.line)
		free(c->temp.line);
	if (c->map.file)
		ft_free_array(c->map.map);
	free(c->map.file);
}

static void	destroy_map(t_cub3d *c)
{
	free(c->map.ea_path);
	free(c->map.we_path);
	free(c->map.no_path);
	free(c->map.so_path);
	if (c->minimap.map)
		ft_free_array(c->minimap.map);
	destroy_file(c);
	close(c->map.fd);
}

static void	destroy_texture(t_image	tex, t_cub3d *c)
{
	if (tex.ptr)
		mlx_destroy_image(c->mlx.ptr, tex.ptr);
}

static void	destroy_images(t_cub3d *c)
{
	destroy_texture(c->mlx.ea_tex.img, c);
	destroy_texture(c->mlx.so_tex.img, c);
	destroy_texture(c->mlx.no_tex.img, c);
	destroy_texture(c->mlx.we_tex.img, c);
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.ptr);
	mlx_destroy_image(c->mlx.ptr, c->menu.img.ptr);
	if (c->menu.resize.ptr)
		mlx_destroy_image(c->mlx.ptr, c->menu.resize.ptr);
}

void	destroy_all(t_cub3d *c)
{
	destroy_images(c);
	destroy_map(c);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	mlx_destroy_display(c->mlx.ptr);
	free(c->mlx.ptr);
}
