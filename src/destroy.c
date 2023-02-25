/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/25 05:21:22 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file_data(t_file_data *file_data)
{
	free(file_data->ea_path);
	free(file_data->we_path);
	free(file_data->no_path);
	free(file_data->so_path);
	free(file_data);
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
	mlx_destroy_image(c->mlx, c->img.image);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	free_file_data(c->file_data);
	free(c->mlx);
	free(c->map_file);
	if (c->map)
		free_array(c->map);
}
