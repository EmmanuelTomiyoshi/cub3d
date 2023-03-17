/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:17:24 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/17 14:18:11 by etomiyos         ###   ########.fr       */
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
		printf("%s: %d\n", c->level.files[i], c->level.name[i].fd);
		i++;
	}
}

void	get_level_colors_and_coordinates(t_cub3d *c)
{
	int		i;
	char	*one_line;
	
	i = 0;
	printf("\n");
	while (i < c->level.count)
	{
		get_colors_and_coordinates(&c->level.name[i], c);
		get_map_content(&c->level.name[i], &one_line, c);
		init_map(&c->level.name[i], c, one_line);
		printf("%s: %d", c->level.files[i], c->level.name[i].c_color);
		printf("| EA_PATH: %s ", c->level.name[i].ea_path);
		printf("| SO_PATH: %s\n", c->level.name[i].so_path);
		i++;
	}
}

// void	get_data(t_cub3d *c)
// {
// 	char	*one_line;

// 	get_colors_and_coordinates(&c->map, c);
// 	get_map_content(&c->map, &one_line, c);
// 	init_map(c, one_line);
// }

void	get_level_info(t_cub3d *c)
{
	int		fd;
	char	*temp_line;
	char	*one_line;

	(void)c;
	fd = open("assets/maps/levels", O_RDONLY);
	if (fd == -1)
		exit_error(MSG_ERR_LEVEL_FILE, FALSE);
	
	temp_line = get_next_line(fd);
	if (temp_line == NULL)
		printf("NULL\n");
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
	
	printf("%s %d\n", one_line, c->level.count);
	printf("\n%s %s\n", c->level.files[1], c->level.files[3]);

	get_level_fd(c);
	get_level_colors_and_coordinates(c);
	free(one_line);
}