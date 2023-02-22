/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 21:24:58 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *msg, t_bool usage)
{
	printf(MSG_ERROR);
	printf("%s\n", msg);
	if (usage == TRUE)
		printf(MSG_USAGE);
	exit(EXIT_FAILURE);
}

void	destroy_all(t_cub3d *c)
{
	mlx_destroy_image(c->mlx, c->img.image);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
	free(c->map);
}
