/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itorgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:22:10 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 00:23:45 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	itorgb(int color, t_rgb *result)
{
	result->r = (color >> 16) & 0xFF;
	result->g = (color >> 8) & 0xFF;
	result->b = color & 0xFF;
}
