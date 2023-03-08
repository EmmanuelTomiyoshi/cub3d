/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/06 16:10:16 by mtomomit         ###   ########.fr       */
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

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL || *array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	destroy_all(t_cub3d *c)
{
	mlx_destroy_image(c->mlx.ptr, c->mlx.img.image);
	mlx_destroy_window(c->mlx.ptr, c->mlx.win);
	mlx_destroy_display(c->mlx.ptr);
	free_file_data(c);
	free(c->mlx.ptr);
	free(c->map.file);
	if (c->map.file)
		free_array(c->map.map);
}
