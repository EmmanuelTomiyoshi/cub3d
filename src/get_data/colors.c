/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:53:35 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 12:15:13 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_color_value(t_map *map, int id, char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (id == 'C')
	{
		map->ceiling.r = r;
		map->ceiling.g = g;
		map->ceiling.b = b;
		map->c_color = get_rgb(r, g, b);
	}
	if (id == 'F')
	{
		map->floor.r = r;
		map->floor.g = g;
		map->floor.b = b;
		map->f_color = get_rgb(r, g, b);
	}
}

static void	check_color_value(char **rgb, t_cub3d *c)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (!rgb[i][0])
		{
			ft_free_array(rgb);
			destroy_all(c);
			exit_error(MSG_ERR_MISSING_RGB, FALSE);
		}
		i++;
	}
}

static void	handle_rgb(char **rgb, char *line, int *i, t_cub3d *c)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (line[*i])
	{
		ft_ignore_spaces(line, i);
		k = 0;
		while (ft_isdigit(line[*i]) && k != 3)
		{
			rgb[j][k++] = line[*i];
			*i += 1;
		}
		ft_ignore_spaces(line, i);
		if (line[*i] != ',' && j != 2)
		{
			ft_free_array(rgb);
			destroy_all(c);
			exit_error(MSG_ERR_TYPE_ID, FALSE);
		}
		*i += 1;
		j++;
	}
	rgb[j] = NULL;
}

static char	**init_rgb(char *line, int *i)
{
	char	**rgb;
	int		j;

	*i += 1;
	ft_ignore_spaces(line, i);
	rgb = ft_calloc(4, sizeof(char *));
	j = 0;
	while (j != 3)
	{
		rgb[j] = ft_calloc(4, sizeof(char));
		j++;
	}
	return (rgb);
}

void	get_colors(t_map *map, int *i, int id, t_cub3d *c)
{
	char	**rgb;

	rgb = init_rgb(c->temp.line, i);
	handle_rgb(rgb, c->temp.line, i, c);
	check_color_value(rgb, c);
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
	{
		ft_free_array(rgb);
		destroy_all(c);
		exit_error(MSG_ERR_COLOR, FALSE);
	}
	get_color_value(map, id, rgb);
	ft_free_array(rgb);
}
