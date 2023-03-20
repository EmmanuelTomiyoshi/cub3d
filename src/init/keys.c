/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:17:29 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 10:19:10 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inittoggle(t_toggle *state)
{
	state->animate = FALSE;
	state->distortion = FALSE;
	state->light_mode = FALSE;
	state->mini_map = FALSE;
}

void	initkeys(t_keyhandle *key)
{
	key->move_left = FALSE;
	key->move_right = FALSE;
	key->move_forward = FALSE;
	key->move_backwards = FALSE;
	key->look_right = FALSE;
	key->look_left = FALSE;
	key->run = FALSE;
	key->speed = DEF_PLAYER_SPEED;
}
