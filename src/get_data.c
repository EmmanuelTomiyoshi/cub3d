/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/23 01:54:22 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ignore_spaces(char *line, int *i)
{
	while (line[*i] == ' ')
		*i += 1;
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
	if (id_floor_ceiling > 0 && ft_strlen(line) > 5) //5 are the minimum of chars of this id
		get_colors(line, &i, id_floor_ceiling, c);
	else if (id_coordinate > 0 && ft_strlen(line) > 2) //2 are the minimum of chars of this id
		get_coordinates(line, &i, id_coordinate, c);
	else
	{
		destroy_all(c);
		exit_error(MSG_ERR_TYPE_ID, FALSE);
	}
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
			c->file_data->infos++;
		free(line);
	}
}
