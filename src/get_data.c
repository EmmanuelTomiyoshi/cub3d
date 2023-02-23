/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/23 01:42:06 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL || *array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_file_data(t_file_data *file_data)
{
	// free(file_data->ea_path);
	// free(file_data->we_path);
	free(file_data->no_path);
	// free(file_data->so_path);
	free(file_data);
}

// int	free_and_return(char **splited_line)
// {
// 	free_split(splited_line);
// 	return (1);
// }

// int	 get_path(t_file_data *file_data, char **splited_line)
// {
// 	if (!ft_strcmp("EA\0", splited_line[0]) && file_data->ea_path == NULL)
// 	{
// 		file_data->ea_path = ft_strtrim(splited_line[1], "\n");
// 		return (free_and_return(splited_line));
// 	}
// 	if (!ft_strcmp("SO\0", splited_line[0]) && file_data->so_path == NULL)
// 	{
// 		file_data->so_path = ft_strtrim(splited_line[1], "\n");
// 		return (free_and_return(splited_line));
// 	}
// 	if (!ft_strcmp("NO\0", splited_line[0]) && file_data->no_path == NULL)
// 	{
// 		file_data->no_path = ft_strtrim(splited_line[1], "\n");
// 		return (free_and_return(splited_line));
// 	}
// 	if (!ft_strcmp("WE\0", splited_line[0]) && file_data->we_path == NULL)
// 	{
// 		file_data->we_path = ft_strtrim(splited_line[1], "\n");
// 		return (free_and_return(splited_line));
// 	}
// 	return (get_color(file_data, splited_line));
// }

// int	get_file_data(char *line, t_file_data *file_data)
// {
// 	char	**splited_line;

// 	splited_line = ft_split(line, ' ');
// 	free(line);
// 	if (splited_line[0] && ft_strchr("EWNSFC\n", splited_line[0][0])
// 		&& splited_line[1] && !splited_line[2])
// 	{
// 		if (splited_line[0][0] == '\n')
// 			return (0);
// 		else
// 			return (get_path(file_data, splited_line));
// 	}
// 	else
// 	{
// 		free_split(splited_line);
// 		exit_error(MSG_INVALID_FILE_FORMAT, FALSE);
// 	}
// 	return (0);
// }

// t_file_data	*get_data(char *file)
// {
// 	t_file_data	*file_data;
// 	int			fd;
// 	int			data;
// 	char		*line;

// 	data = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		exit_error(MSG_INVALID_FILE, 0);
// 	file_data = (t_file_data *)ft_calloc(1, sizeof(t_file_data));
// 	file_data->fd = fd;
// 	line = get_next_line(fd);
// 	while (line && data < 6)
// 	{
// 		data += get_file_data(line, file_data);
// 		line = get_next_line(fd);
// 	}
// 	if (line == NULL)
// 		exit_error(MSG_INVALID_FILE_FORMAT, FALSE);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	return (file_data);
// }

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

int	is_coordinate(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (-1);
}

int	is_floor_or_ceiling(int c)
{
	if (c == 'C' || c == 'F')
		return (c);
	return (-1);
}

void	ignore_spaces(char *line, int *i)
{
	while (line[*i] == ' ')
		*i += 1;
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

void	get_colors(char *line, int *i, int id, t_cub3d *c)
{
	int		j;
	int		k;
	char	**rgb;

	j = 0;
	k = 0;
	*i += 1;
	ignore_spaces(line, i);
	rgb = ft_calloc(4, sizeof(char *));
	while (j != 3)
	{
		rgb[j] = ft_calloc(4, sizeof(char));
		j++;
	}
	j = 0;
	while (line[*i])
	{
		ignore_spaces(line, i);
		k = 0;
		while (ft_isdigit(line[*i]) && k != 3)
		{
			rgb[j][k] = line[*i];
			*i += 1;
			k++;
		}
		printf("|%s|\n", rgb[j]);
		ignore_spaces(line, i);
		if (line[*i] != ',' && line[*i] != '\n')
			exit_error(MSG_ERR_TYPE_ID, FALSE);
		*i += 1;
		j++;
	}
	rgb[j] = NULL;
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
	{
		free_array(rgb);
		exit_error(MSG_ERR_COLOR, FALSE);
	}
	get_color_value(id, rgb, c);
	free_array(rgb);
}

void	get_path(int id, char *path, t_cub3d *c)
{
	if (id == 'N')
		c->file_data->no_path = ft_strdup(path);
	if (id == 'S')
		c->file_data->so_path = ft_strdup(path);
	if (id == 'W')
		c->file_data->we_path = ft_strdup(path);
	if (id == 'E')
		c->file_data->ea_path = ft_strdup(path);
}

void	get_coordinates(char *line, int *i, int id, t_cub3d *c)
{
	char	*path;
	int		j;

	*i += 1;
	if (line[*i] != 'O' && line[*i] != 'E' && line[*i] != 'A')
		exit_error(MSG_ERR_TYPE_ID, FALSE);
	path = ft_calloc(255, sizeof(char));
	j = 0;
	*i += 1;
	ignore_spaces(line, i);
	while (line[*i] != ' ' && line[*i] != '\n')
	{
		path[j] = line[*i];
		*i += 1;
		j++;
	}
	//----check if the value is right----
	printf("|%s|\n", path);
	get_path(id, path, c);
	free(path);
}

int	check_type_identifier(char *line, t_cub3d *c)
{
	int	i;
	int	id_floor_ceiling;
	int	id_coordinate;

	i = 0;
	ignore_spaces(line, &i);
	if (line[i] == '\n')
		return (0);
	id_floor_ceiling = is_floor_or_ceiling(line[i]);
	id_coordinate = is_coordinate(line[i]);
	if (id_floor_ceiling > 0 && ft_strlen(line) > 5) //5 min ground
		get_colors(line, &i, id_floor_ceiling, c);
	else if (id_coordinate > 0 && ft_strlen(line) > 2) //2 min coordinates
		get_coordinates(line, &i, id_coordinate, c);
	else
		exit_error(MSG_ERR_TYPE_ID, FALSE);
	return (1);
}

void	get_data(t_cub3d *c)
{
	char	*line;

	c->file_data = (t_file_data *)ft_calloc(1, sizeof(t_file_data));
	c->file_data->infos = 0;
	while (c->file_data->infos != 6)
	{
		line = get_next_line(c->map_fd);
		if (check_type_identifier(line, c) == 1)
			c->file_data->infos++;;
		free(line);
	}
	free_file_data(c->file_data);
}
