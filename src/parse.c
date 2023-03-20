/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 09:41:55 by etomiyos         ###   ########.fr       */
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

static t_bool	can_open_file(t_cub3d *c, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	c->map.fd = fd;
	return (TRUE);
}

void	is_directory(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		exit_error(MSG_ERR_IS_DIR, FALSE);
	}
}

void	invalid_args(int argc, char **argv, t_cub3d *c)
{
	if (argc < 2)
		exit_error(MSG_FEW_ARGS, TRUE);
	if (argc > 3)
		exit_error(MSG_MANY_ARGS, TRUE);
	if (argc == 3)
	{
		is_directory(argv[2]);
		c->level.flag = TRUE;
		c->level.file_path = ft_strdup(argv[2]);
	}
	else
		c->level.flag = FALSE;
	if (is_valid_file_extension(argv[1]) == FALSE)
		exit_error(MSG_ERR_FILENAME, TRUE);
	if (can_open_file(c, argv[1]) == FALSE)
		exit_error(MSG_ERR_OPEN_FILE, TRUE);
}
