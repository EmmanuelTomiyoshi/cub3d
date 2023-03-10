/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/10 15:39:00 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_cub3d *c)
{
	rotate_vector(&c->player.dir, 1);
	rotate_vector(&c->player.camera.plane, 1);
}

void	look_right(t_cub3d *c)
{
	rotate_vector(&c->player.dir, 359);
	rotate_vector(&c->player.camera.plane, 359);
}
