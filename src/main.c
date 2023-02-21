/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 12:11:31 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx);
	return (0);
}

int	render(t_cub3d *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->img.image, 0, 0);
	return (0);
}

void	destroy_all(t_cub3d *c)
{
	mlx_destroy_image(c->mlx, c->img.image);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	(void)argv;
	invalid_args(argc);
	init(&cub3d);
	mlx_expose_hook(cub3d.win, &render, &cub3d);
	mlx_hook(cub3d.win, 17, 1L << 24, end_loop, &cub3d);
	mlx_loop(cub3d.mlx);
	return (EXIT_SUCCESS);
}
