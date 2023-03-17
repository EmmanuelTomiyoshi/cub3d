/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:18:32 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/17 12:18:56 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_btn_pos(t_button *btn, int x, int y)
{
	if (!btn)
		return ;
	btn->x = x;
	btn->y = y;
	if (btn->x)
		return ;
}

void	get_btn_size(t_button *btn, int width, int height)
{
	if (!btn)
		return ;
	btn->width = width;
	btn->height = height;
}
