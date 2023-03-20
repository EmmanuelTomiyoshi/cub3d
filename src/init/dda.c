/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:19:45 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 10:22:05 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inithit(t_hit *hit)
{
	hit->hit = FALSE;
	hit->side = 0;
}

void	initvector(t_vector *v)
{
	v->x = 0;
	v->y = 0;
}

void	initdda(t_dda *dda)
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
