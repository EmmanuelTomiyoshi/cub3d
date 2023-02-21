/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 12:42:22 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_cub3d *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->img.image, 0, 0);
	return (0);
}

int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx);
	return (0);
}

void	loop(t_cub3d *c)
{
	mlx_expose_hook(c->win, &render, c);
	mlx_hook(c->win, 17, 1L << 24, end_loop, c);
	mlx_loop(c->mlx);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	(void)argv;
	invalid_args(argc);
	init(&cub3d);
	loop(&cub3d);
	return (EXIT_SUCCESS);
}
