/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:00 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 16:25:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_argc(int argc)
{
	if (argc < 2)
		exit_error(MSG_FEW_ARGS, TRUE);
	if (argc > 3)
		exit_error(MSG_MANY_ARGS, TRUE);
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

void	check_argv_flag_levels(char *flag_level, t_cub3d *c)
{
	is_directory(flag_level);
	c->level.fd = open(flag_level, O_RDONLY);
	if (c->level.fd == -1)
		exit_error(MSG_ERR_LEVEL_FILE, FALSE);
	else
		c->level.flag = TRUE;
}