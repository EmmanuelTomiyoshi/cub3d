/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/22 17:08:01 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file_data(t_file_data *file_data)
{
	free(file_data->ea_path);
	free(file_data->we_path);
	free(file_data->no_path);
	free(file_data->so_path);
	free(file_data);
}

int	free_and_return(char **splited_line)
{
	free_split(splited_line);
	return (1);
}

int	get_path(t_file_data *file_data, char **splited_line)
{
	if (!ft_strcmp("EA\0", splited_line[0]) && file_data->ea_path == NULL)
	{
		file_data->ea_path = ft_strtrim(splited_line[1], "\n");
		return (free_and_return(splited_line));
	}
	if (!ft_strcmp("SO\0", splited_line[0]) && file_data->so_path == NULL)
	{
		file_data->so_path = ft_strtrim(splited_line[1], "\n");
		return (free_and_return(splited_line));
	}
	if (!ft_strcmp("NO\0", splited_line[0]) && file_data->no_path == NULL)
	{
		file_data->no_path = ft_strtrim(splited_line[1], "\n");
		return (free_and_return(splited_line));
	}
	if (!ft_strcmp("WE\0", splited_line[0]) && file_data->we_path == NULL)
	{
		file_data->we_path = ft_strtrim(splited_line[1], "\n");
		return (free_and_return(splited_line));
	}
	return (get_color(file_data, splited_line));
}

int	get_file_data(char *line, t_file_data *file_data)
{
	char	**splited_line;

	splited_line = ft_split(line, ' ');
	free(line);
	if (splited_line[0] && ft_strchr("EWNSFC\n", splited_line[0][0]) \
		&& splited_line[1] && !splited_line[2])
	{
		if (splited_line[0][0] == '\n')
			return (0);
		else
			return (get_path(file_data, splited_line));
	}
	else
	{
		free_split(splited_line);
		exit_error(MSG_INVALID_FILE_FORMAT, FALSE);
	}
	return (0);
}

t_file_data	*get_data(char *file)
{
	t_file_data	*file_data;
	int			fd;
	int			data;
	char		*line;

	data = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(MSG_INVALID_FILE, 0);
	file_data = (t_file_data *)ft_calloc(1, sizeof(t_file_data));
	file_data->fd = fd;
	line = get_next_line(fd);
	while (line && data < 6)
	{
		data += get_file_data(line, file_data);
		line = get_next_line(fd);
	}
	if (line == NULL)
		exit_error(MSG_INVALID_FILE_FORMAT, FALSE);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	printf("%s\n", file_data->ea_path);
	printf("%s\n", file_data->so_path);
	printf("%s\n", file_data->no_path);
	printf("%s\n", file_data->we_path);
	printf("%i\n", file_data->c_color);
	printf("%i\n", file_data->f_color);
	return (file_data);
}
