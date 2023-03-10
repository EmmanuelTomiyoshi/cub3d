/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:31:54 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/10 17:00:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rad(double num)
{
	return (((num * M_PI) / 180));
}

void	rotate_vector(t_vector *vector, double ang)
{
	double	temp_x;

	temp_x = vector->x;
	vector->x = vector->x * cos(rad(ang)) + vector->y * -sin(rad(ang));
	vector->y = temp_x * sin(rad(ang)) + vector->y * cos(rad(ang));
}
