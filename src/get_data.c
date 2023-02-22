/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/22 13:27:25 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **splited_line)
{
	size_t	i;

	i = 0;
	while (splited_line[i])
	{
		free(splited_line[i]);
		i++;
	}
	free(splited_line[i]);
	free(splited_line);
}

int	get_path(t_file_data *file_data, char **splited_line, char *line)
{
	if (!ft_strcmp("EA\0", splited_line[0]) && file_data->ea_path == NULL)
	{
		file_data->ea_path = ft_strtrim(splited_line[1], "\n");
		return (1);
	}
	if (!ft_strcmp("SO\0", splited_line[0]) && file_data->so_path == NULL)
	{
		file_data->so_path = ft_strtrim(splited_line[1], "\n");
		return (1);
	}
	if (!ft_strcmp("NO\0", splited_line[0]) && file_data->no_path == NULL)
	{
		file_data->no_path = ft_strtrim(splited_line[1], "\n");
		return (1);
	}
	if (!ft_strcmp("WE\0", splited_line[0]) && file_data->we_path == NULL)
	{
		file_data->we_path = ft_strtrim(splited_line[1], "\n");
		return (1);
	}
	return (get_color(file_data, splited_line, line));
}

int	get_file_data(char *line, t_file_data *file_data)
{
	char	**splited_line;
	char	*path;

	splited_line = ft_split(line, ' ');
	if (splited_line[0] && ft_strchr("EWNSFC\n", splited_line[0][0]) \
		&& splited_line[1] && !splited_line[2])
	{
		if (splited_line[0][0] == '\n')
			return (0);
		else
			return (get_path(file_data, splited_line, line));
	}
	else
	{
		free_split(splited_line);
		free(line);
		exit_error(MSG_INVALID_FILE_FORMAT, FALSE);
	}
	free_split(splited_line);
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
	line = get_next_line(fd);
	while (line && data < 6)
	{
		data += get_file_data(line, file_data);
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		exit_error(MSG_INVALID_FILE_FORMAT, FALSE);
}
