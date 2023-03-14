/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:01 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 09:58:19 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x <= img->win_width && y <= img->win_height && y >= 0 && x >= 0)
	{
		dst = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel) / 8);
		*(unsigned int *) dst = color;
	}
}
