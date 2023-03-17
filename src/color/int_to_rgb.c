/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:22:45 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 11:23:52 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	intorgb(int *r, int *g, int *b, unsigned int *color)
{
	*r = (*color >> 16) & 0xFF;
	*g = (*color >> 8) & 0xFF;
	*b = *color & 0xFF;
}

void	itorgb(int color, t_rgb *result)
{
	result->r = (color >> 16) & 0xFF;
	result->g = (color >> 8) & 0xFF;
	result->b = color & 0xFF;
}
