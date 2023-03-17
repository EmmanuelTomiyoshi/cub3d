/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:10:43 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 12:12:47 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	distortion(t_cub3d *c)
{
	c->distortion = !c->distortion;
}

void	animate(t_cub3d *c)
{
	c->animate = !c->animate;
}

void	show_minimap(t_cub3d *c)
{
	c->mini_map = !c->mini_map;
}
