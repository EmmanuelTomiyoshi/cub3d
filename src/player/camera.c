/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/12 14:27:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_cub3d *c)
{
	rotate_vector(&c->player.dir, 3.14);
	rotate_vector(&c->player.camera.plane, 3.14);
}

void	look_right(t_cub3d *c)
{
	rotate_vector(&c->player.dir, 356.86);
	rotate_vector(&c->player.camera.plane, 356.86);
}
