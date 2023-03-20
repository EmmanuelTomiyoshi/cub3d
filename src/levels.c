/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:17:24 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 10:06:22 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_level_fd(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->level.count)
	{
		c->level.temp = ft_strjoin("assets/maps/", c->level.files[i]);
		c->level.name[i].fd = open(c->level.temp, O_RDONLY);
		if (c->level.name[i].fd == -1)
		{
			free(c->level.temp);
			destroy_level(c);
			exit_error(MSG_ERR_LEVEL_FILE, FALSE);
		}
		free(c->level.temp);
		i++;
	}
}

void	get_level_colors_and_coordinates(t_cub3d *c)
{
	int		i;
	char	*one_line;

	i = 0;
	while (i < c->level.count)
	{
		get_colors_and_coordinates(&c->level.name[i], c);
		get_map_content(&c->level.name[i], &one_line, c);
		get_map(&c->level.name[i], c, one_line);
		get_minimap(&c->level.name[i]);
		get_texture(&c->level.name[i], c);
		i++;
	}
}

void	check_level_filenames(char **one_line, t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->level.count)
	{
		if (ft_strchr(c->level.files[i], '\n')
			&& c->level.files[i][ft_strlen(c->level.files[i])] != EOF)
		{
			c->level.files[i][ft_strlen(c->level.files[i]) - 1] = '\0';
		}
		if (is_valid_file_extension(c->level.files[i]) == FALSE)
		{
			free(*one_line);
			destroy_all(c);
			exit_error(MSG_ERR_FILE_NAME, FALSE);
		}
		i++;
	}
}

void	get_level_info(t_cub3d *c)
{
	int		fd;
	char	*temp_line;
	char	*one_line;

	(void)c;
	c->level.count = 0;
	if (c->level.flag == TRUE)
		fd = open(c->level.file_path, O_RDONLY);
	else
		fd = open("/assets/maps/levels", O_RDONLY);
	if (fd == -1)
	{
		destroy_all(c);
		ft_free_array(c->map.map);
		exit_error(MSG_ERR_LEVEL_FILE, FALSE);
	}
	temp_line = get_next_line(fd);
	if (temp_line == NULL)
	{
		free(temp_line);
		destroy_all(c);
		ft_free_array(c->map.map);
		exit_error(MSG_ERR_EMPY_LEVEL_FILE, FALSE);
	}
	c->level.count = 0;
	one_line = ft_strdup("");
	while (temp_line)
	{
		one_line = ft_merge(one_line, temp_line);
		free(temp_line);
		temp_line = get_next_line(fd);
		c->level.count++;
	}
	free(temp_line);
	c->level.files = ft_split(one_line, '\n');
	c->level.name = ft_calloc(c->level.count, sizeof(t_map));
	check_level_filenames(&one_line, c);
	get_level_fd(c);
	get_level_colors_and_coordinates(c);
	free(one_line);
}
