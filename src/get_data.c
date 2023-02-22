/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/22 11:28:46 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **splited_line)
{
	size_t	i;
}

int	get_data(char *line, t_file_data *file_data)
{
	char	**splited_line;
	char	*path;

	splited_line = ft_split(line, ' ');
	if (splited_line && ft_strchr("EWNSFC\n", splited_line[0][0]))
	{
		if (splited_line[0][0] == '\n')
			return (0);
	}
	else
	{
		free(line);
		exit_error(MSG_INVALID_FILE_FORMAT, 0);
	}
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
	file_data = (t_file_data *)malloc(sizeof(t_file_data) * 1);
	line = get_next_line(fd);
	while (line && data < 6)
	{
		data += get_data(line, file_data);
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		exit_error(MSG_INVALID_FILE_FORMAT, 0);
}
