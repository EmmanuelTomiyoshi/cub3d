/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:53:35 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 15:02:32 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	itorgb(int color, t_rgb *result)
{
	result->r = (color >> 16) & 0xFF;
	result->g = (color >> 8) & 0xFF;
	result->b = color & 0xFF;
	// printf("Result color: (%d, %d, %d)\n", result->r, result->g, result->b);
}

int	is_floor_or_ceiling(int c)
{
	if (c == 'C' || c == 'F')
		return (c);
	return (-1);
}

void	get_color_value(int id, char **rgb, t_cub3d *c)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (id == 'C')
	{
		c->map.ceiling.r = r;
		c->map.ceiling.g = g;
		c->map.ceiling.b = b;
		c->map.c_color = get_rgb(r, g, b);
	}
	if (id == 'F')
	{
		c->map.floor.r = r;
		c->map.floor.g = g;
		c->map.floor.b = b;
		c->map.f_color = get_rgb(r, g, b);
	}
}

char	**init_rgb(char *line, int *i)
{
	char	**rgb;
	int		j;

	*i += 1;
	ignore_spaces(line, i);
	rgb = ft_calloc(4, sizeof(char *));
	j = 0;
	while (j != 3)
	{
		rgb[j] = ft_calloc(4, sizeof(char));
		j++;
	}
	return (rgb);
}

void	handle_rgb(char **rgb, char *line, int *i, t_cub3d *c)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (line[*i])
	{
		ignore_spaces(line, i);
		k = 0;
		while (ft_isdigit(line[*i]) && k != 3)
		{
			rgb[j][k++] = line[*i];
			*i += 1;
		}
		ignore_spaces(line, i);
		if (line[*i] != ',' && line[*i] != '\n')
		{
			destroy_all(c);
			exit_error(MSG_ERR_TYPE_ID, FALSE);
		}
		*i += 1;
		j++;
	}
	rgb[j] = NULL;
}

void	get_colors(char *line, int *i, int id, t_cub3d *c)
{
	char	**rgb;

	rgb = init_rgb(line, i);
	handle_rgb(rgb, line, i, c);
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
	{
		ft_free_array(rgb);
		destroy_all(c);
		exit_error(MSG_ERR_COLOR, FALSE);
	}
	get_color_value(id, rgb, c);
	ft_free_array(rgb);
}
