/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:55:47 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 19:25:13 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_valid_file_extension(char *filename)
{
	if (!ft_strchr(filename, '.') || ft_strlen(filename) < 5)
		return (FALSE);
	if (filename[ft_strlen(filename) - 1] != 'b')
		return (FALSE);
	if (ft_strcmp(ft_strrchr(filename, '.'), ".cub"))
		return (FALSE);
	return (TRUE);
}

void	validate_level_name(char *input_file, t_cub3d *c)
{
	char	*temp_line;

	if (is_valid_file_extension(input_file) == FALSE)
		exit_error(MSG_ERR_FILENAME, TRUE);
	temp_line = get_next_line(c->level.fd);
	if (temp_line == NULL)
	{
		free(temp_line);
		exit_error(MSG_ERR_EMPY_LEVEL_FILE, FALSE);
	}
	c->level.count = 0;
	c->level.one_line = ft_strdup("");
	while (temp_line)
	{
		c->level.one_line = ft_merge(c->level.one_line, temp_line);
		if (ft_strchr(temp_line, '\n') && temp_line[ft_strlen(temp_line)] != EOF)
		{
			temp_line[ft_strlen(temp_line) - 1] = '\0';
		}
		if (is_valid_file_extension(temp_line) == FALSE)
		{
			free(temp_line);
			free(c->level.one_line);
			exit_error(MSG_ERR_FILENAME, TRUE);
		}
		free(temp_line);
		temp_line = get_next_line(c->level.fd);
		c->level.count++;
	}
	free(temp_line);
}

void	validate_level_file(char *input_file, t_cub3d *c)
{
	int	i;

	c->level.name[0].fd = open(input_file, O_RDONLY);
	if (c->level.name[0].fd < 0)
	{
		destroy_level(c);
		exit_error(MSG_ERR_LEVEL_FILE, FALSE);
	}
	i = 1;
	while (i < c->level.count)
	{
		c->level.temp = ft_strjoin("assets/maps/", c->level.files[i]);
		c->level.name[i].fd = open(c->level.temp, O_RDONLY);
		if (c->level.name[i].fd < 0)
		{
			free(c->level.temp);
			destroy_level(c);
			exit_error(MSG_ERR_LEVEL_FILE, FALSE);
		}
		free(c->level.temp);
		i++;
	}
}
