/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 23:57:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file_data(t_cub3d *c)
{
	free(c->map.ea_path);
	free(c->map.we_path);
	free(c->map.no_path);
	free(c->map.so_path);
}

void	destroy_all(t_cub3d *c)
{
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.image);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win.ptr);
	mlx_destroy_display(c->mlx.ptr);
	free_file_data(c);
	free(c->mlx.ptr);
	free(c->map.file);
	if (c->temp.line)
		free(c->temp.line);
	if (c->map.file)
		ft_free_array(c->map.map);
}
