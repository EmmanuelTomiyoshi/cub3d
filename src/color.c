/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:09:50 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/22 17:08:51 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all(t_file_data *file_data, char **splited_line, int exit_code, char **rgb)
{
	char	*line;

	free_split(rgb);
	free_split(splited_line);
	if (exit_code == 0)
	{
		line = get_next_line(file_data->fd);
		while (line)
		{
			free(line);
			line = get_next_line(file_data->fd);
		}
		free(line);
		free_file_data(file_data);
		exit_error(MSG_INVALID_FILE_FORMAT, FALSE);
	}
	return (exit_code);
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	if (split != NULL)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split[i]);
	}
	free(split);
}

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

t_bool	verify_only_number(char *rgb)
{
	size_t	i;

	i = 0;
	if (rgb == NULL)
		return (FALSE);
	while (rgb[i] && ft_isdigit(rgb[i]))
		i++;
	if (!rgb[i])
		return (TRUE);
	else
		return (FALSE);
}

int	get_color(t_file_data *file_data, char **splited_line)
{
	char	**rgb;
	char	*color;

	rgb = NULL;
	if ((!ft_strcmp("F\0", splited_line[0]) && file_data->f_color == 0) || \
		(!ft_strcmp("C\0", splited_line[0]) && file_data->c_color == 0))
	{
		color = ft_strtrim(splited_line[1], "\n");
		rgb = ft_split(color, ',');
		free(color);
		if (!verify_only_number(rgb[0]) && !verify_only_number(rgb[1]) && \
			!verify_only_number(rgb[2]) && rgb[3] == NULL)
			free_all(file_data, splited_line, 0, rgb);
		if (!ft_strcmp("C\0", splited_line[0]))
			file_data->c_color = get_rgb(atoi(rgb[0]), atoi(rgb[1]), atoi(rgb[2]));
		if (!ft_strcmp("F\0", splited_line[0]))
			file_data->f_color = get_rgb(atoi(rgb[0]), atoi(rgb[1]), atoi(rgb[2]));
		if ((!ft_strcmp("F\0", splited_line[0]) && file_data->f_color == 0) || \
			(!ft_strcmp("C\0", splited_line[0]) && file_data->c_color == 0))
				free_all(file_data, splited_line, 0, rgb);
		return (free_all(file_data, splited_line, 1, rgb));
	}
	free_all(file_data, splited_line, 0, rgb);
	return (0);
}
