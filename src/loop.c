/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:41:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 21:46:56 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	end_loop(t_cub3d *c);

void	loop(t_cub3d *c)
{
	mlx_hook(c->win, 17, 0, end_loop, c);
	mlx_expose_hook(c->win, &render, c);
	mlx_loop(c->mlx);
}

static int	end_loop(t_cub3d *c)
{
	mlx_loop_end(c->mlx);
	return (0);
}
