/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:57:49 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 21:06:44 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initkeys(t_keyhandle *key)
{
	key->move_left = FALSE;
	key->move_right = FALSE;
	key->move_foward = FALSE;
	key->move_backwards = FALSE;
	key->look_right = FALSE;
	key->look_left = FALSE;
	key->run = FALSE;
	key->speed = DEF_PLAYER_SPEED;
}


void	inittoggle(t_toggle *state)
{
	state->animate = FALSE;
	state->distortion = FALSE;
	state->light_mode = FALSE;
	state->mini_map = FALSE;
}

void	inittemp(t_temp *tmp)
{
	tmp->line = NULL;
}

void	initdraw(t_draw *draw)
{
	draw->wall_line_height = 0;
	draw->start = 0;
	draw->end = 0;
	draw->tex_x = 0;
	draw->tex_y = 0;
	draw->wall_x = 0;
	draw->tex_pos = 0;
	draw->step = 0;
	draw->color = 0;
}

void    initdda(t_dda *dda)
{
	dda->pixel = 0;
	dda->perpendicular = 0;
	inithit(&dda->hit);
	initvector(&dda->delta);
	initvector(&dda->to_side);
	initvector(&dda->step);
	initvector(&dda->raydir);
	initvector(&dda->line_size);
	initvector(&dda->wall_pos);
}