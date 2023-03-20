/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:10:43 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/19 23:57:07 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	distortion(t_cub3d *c)
{
	c->state.distortion = !c->state.distortion;
}

void	animate(t_cub3d *c)
{
	c->state.animate = !c->state.animate;
}

void	show_minimap(t_cub3d *c)
{
	c->state.mini_map = !c->state.mini_map;
}

void	show_menu(t_cub3d *c)
{
	c->menu.active = !c->menu.active;
}