/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 21:46:34 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	improved_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr;
	dest += (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw(t_cub3d *c)
{
	improved_mlx_pixel_put(&(c->img), 200, 200, 0x00FFDA29);
}

void	init(char **argv, t_cub3d *c)
{
	c->map = ft_strdup(argv[1]);
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "cub3d");
	c->img.image = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (c->mlx == NULL || c->win == NULL || c->img.image == NULL)
		exit_error(MSG_ERR_MLX_INIT, FALSE);
	c->img.addr = mlx_get_data_addr(c->img.image, &c->img.bits_per_pixel,
			&c->img.line_length, &c->img.endian);
	draw(c);
}
