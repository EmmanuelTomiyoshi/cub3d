/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 16:57:01 by etomiyos         ###   ########.fr       */
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

void	get_level_info(t_cub3d *c)
{
	(void)c;
	// get_level_colors_and_coordinates(c);
	// free(one_line);
}

void	get_level_data(char **argv, t_cub3d *c)
{
	validate_level_name(argv[1], c);
	c->level.files = ft_split(c->level.one_line, '\n');
	c->level.name = ft_calloc(c->level.count + 1, sizeof(t_map));
	validate_level_file(argv[1], c);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	//
	invalid_args(argc, argv, &cub3d);
	get_level_data(argv, &cub3d);
	//

	init(argv, &cub3d);
	get_data(&cub3d);
	init_minimap(&cub3d.map);
	get_level_info(&cub3d);
	get_texture(&cub3d.map, &cub3d);
	loop(&cub3d);
	destroy_all(&cub3d);
	return (EXIT_SUCCESS);
}
