/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:53:35 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/23 02:12:02 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	if (r == 0 && b == 0 && g == 0)
		r = 1;
	if ((r > 255 || r < 0) || (b > 255 || b < 0) || (g > 255 || g < 0))
		return (0);
	rgb += (r & 0xFF) << 16;
	rgb += (g & 0xFF) << 8;
	rgb += (b & 0xFF);
	return (rgb);
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
		c->file_data->c_color = get_rgb(r, g, b);
	if (id == 'F')
		c->file_data->f_color = get_rgb(r, g, b);
	//----check if the value is right----
	//printf("c: |%d| f: |%d|\n", c->file_data->c_color, c->file_data->f_color);
	//https://www.checkyourmath.com/convert/color/decimal_rgb.php
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
		printf("|%s|\n", rgb[j]);
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
		free_array(rgb);
		destroy_all(c);
		exit_error(MSG_ERR_COLOR, FALSE);
	}
	get_color_value(id, rgb, c);
	free_array(rgb);
}
