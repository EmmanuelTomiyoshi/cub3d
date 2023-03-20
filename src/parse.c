/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 20:52:31 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_valid_file_extension(char *filename, char lastchar, char *extension)
{
	if (filename[0] == '.' && ft_strchr_count(filename, '.') > 2)
		return (FALSE);
	if (!ft_strchr(filename, '.') || ft_strlen(filename) < 5)
		return (FALSE);
	if (filename[ft_strlen(filename) - 1] != lastchar)
		return (FALSE);
	if (ft_strcmp(ft_strrchr(filename, '.'), extension))
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
		exit_error(MSG_ERR_IS_DIR, TRUE);
	}
}

void	check_mlx_init(t_cub3d *c)
{
	c->mlx.ptr = mlx_init();
	if (c->mlx.ptr == NULL)
		exit_error(MSG_ERR_MLX_INIT, FALSE);
}

void	invalid_args(int argc, char **argv, t_cub3d *c)
{
	if (argc < 2)
		exit_error(MSG_FEW_ARGS, TRUE);
	if (argc > 3)
		exit_error(MSG_MANY_ARGS, TRUE);
	check_mlx_init(c);
	c->level.count = 0;
	if (argc == 3)
	{
		is_directory(argv[2]);
		c->level.flag = TRUE;
		c->level.file_path = argv[2];
	}
	else
		c->level.flag = FALSE;
	if (is_valid_file_extension(argv[1], 'b', ".cub") == FALSE)
	{
		destroy_mlx(c);
		exit_error(MSG_ERR_FILE_CUB, TRUE);
	}
	if (can_open_file(c, argv[1]) == FALSE)
	{
		destroy_mlx(c);
		exit_error(MSG_ERR_OPEN_FILE, TRUE);
	}
}
