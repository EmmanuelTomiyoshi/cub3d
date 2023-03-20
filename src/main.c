/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 19:30:34 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_level_info(t_cub3d *c)
{
	(void)c;
	// get_level_colors_and_coordinates(c);
	// free(one_line);
}

void	new_levels(t_cub3d *c)
{
	c->level.files = ft_split(c->level.one_line, '\n');
	c->level.name = ft_calloc(c->level.count + 1, sizeof(t_map));
}

void	get_level_data(char **argv, t_cub3d *c)
{
	validate_level_name(argv[1], c);
	new_levels(c);
	validate_level_file(argv[1], c);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	//esses dois estão mais do que certos
	invalid_args(argc, argv, &cub3d);
	get_level_data(argv, &cub3d);


	//parei no init
	init(argv, &cub3d);
	get_data(&cub3d);
	init_minimap(&cub3d.map);
	get_level_info(&cub3d);
	get_texture(&cub3d.map, &cub3d);
	loop(&cub3d);
	destroy_all(&cub3d);
	return (EXIT_SUCCESS);
}
