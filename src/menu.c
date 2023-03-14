/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:58:53 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 21:25:20 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	import_menu_image(t_cub3d *c)
{
	int	width;
	int	height;

	c->mlx.img.original = c->mlx.img.image;
	c->mlx.img.image = mlx_xpm_file_to_image(c->mlx.ptr,
			"./src/paused.xpm", &width, &height);
	draw_button(c->menu.fullscreen, c);
	draw_button(c->menu.crosshair, c);
}

int	show_menu(t_cub3d *c)
{
	void	*tmp_img;

	c->menu.active = !c->menu.active;
	if (c->menu.active)
		import_menu_image(c);
	else
	{
		tmp_img = c->mlx.img.image;
		mlx_destroy_image(c->mlx.ptr, tmp_img);
		c->mlx.img.image = c->mlx.img.original;
	}
	return (0);
}

//	// t_rgb	foreground;

// itorgb(0, &foreground);
// blend(foreground, c->map.floor, MENU_OPACITY, &c->map.floor);
// c->map.f_color = get_rgb(c->map.floor.r, c->map.floor.g, c->map.floor.b);
// blend(foreground, c->map.ceiling, MENU_OPACITY, &c->map.ceiling);
// c->map.c_color = get_rgb(c->map.ceiling.r,
//		c->map.ceiling.g, c->map.ceiling.b);
// blend(foreground, c->map.c_cube1, MENU_OPACITY, &c->map.c_cube1);
// c->map.cube1 = get_rgb(c->map.c_cube1.r, c->map.c_cube1.g, c->map.c_cube1.b);
// blend(foreground, c->map.c_cube2, MENU_OPACITY, &c->map.c_cube2);
// c->map.cube2 = get_rgb(c->map.c_cube2.r, c->map.c_cube2.g, c->map.c_cube2.b);
