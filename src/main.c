/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 16:26:52 by etomiyos         ###   ########.fr       */
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

void	get_level_info(t_cub3d *c)
{
	(void)c;
	//
	// fd = open("assets/maps/levels", O_RDONLY);
	// if (fd == -1)
	// 	exit_error(MSG_ERR_LEVEL_FILE, FALSE);

	//----

	//----


	//
	// c->level.files = ft_split(one_line, '\n');
	// c->level.name = ft_calloc(c->level.count, sizeof(t_map));
	//

	
	// get_level_fd(c);
	// get_level_colors_and_coordinates(c);
	// free(one_line);
}

void	read_levels(char *input_file, t_cub3d *c)
{
	char	*temp_line;
	char	*one_line;

	if (is_valid_file_extension(input_file) == FALSE)
		exit_error(MSG_ERR_FILENAME, TRUE);

	temp_line = get_next_line(c->level.fd);
	if (temp_line == NULL)
	{
		free(temp_line);
		exit_error(MSG_ERR_EMPY_LEVEL_FILE, FALSE);
	}
	c->level.count = 0;
	one_line = ft_strdup("");
	while (temp_line)
	{
		one_line = ft_merge(one_line, temp_line);
		if (ft_strchr(temp_line, '\n') && temp_line[ft_strlen(temp_line)] != EOF)
		{
			temp_line[ft_strlen(temp_line) - 1] = '\0';
		}
		if (is_valid_file_extension(temp_line) == FALSE)
		{
			free(temp_line);
			free(one_line);
			exit_error(MSG_ERR_FILENAME, TRUE);
		}
		free(temp_line);
		temp_line = get_next_line(c->level.fd);
		c->level.count++;
		printf("%d\n", c->level.count);
	}
	free(temp_line);

	// free(one_line);
	exit(1);			////////
}

void	get_level_data(int argc, char **argv, t_cub3d *c)
{
	(void)argc;
	read_levels(argv[1], c);
	if (is_valid_file_extension(argv[1]) == FALSE)
		exit_error(MSG_ERR_FILENAME, TRUE);
	if (can_open_file(c, argv[1]) == FALSE)
		exit_error(MSG_ERR_OPEN_FILE, TRUE);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	invalid_args(argc, argv, &cub3d);
	get_level_data(argc, argv, &cub3d);
	init(argv, &cub3d);
	get_data(&cub3d);
	init_minimap(&cub3d.map);
	get_level_info(&cub3d);
	get_texture(&cub3d.map, &cub3d);
	loop(&cub3d);
	destroy_all(&cub3d);
	return (EXIT_SUCCESS);
}
