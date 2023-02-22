/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/22 09:46:21 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_valid_file_extension(char *filename)
{
	if (!ft_strchr(filename, '.') || ft_strlen(filename) < 5)
		return (FALSE);
	if (filename[ft_strlen(filename) - 1] != 'b')
		return (FALSE);
	if (ft_strcmp(ft_strchr(filename, '.'), ".cub"))
		return (FALSE);
	return (TRUE);
}

t_bool	can_open_file(char	*filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close (fd);
	return (TRUE);
}

void	invalid_args(int argc, char **argv)
{
	if (argc < 2)
		exit_error(MSG_FEW_ARGS, TRUE);
	if (argc > 2)
		exit_error(MSG_MANY_ARGS, TRUE);
	if (is_valid_file_extension(argv[1]) == FALSE)
		exit_error(MSG_ERR_FILENAME, TRUE);
	if (can_open_file(argv[1]) == FALSE)
		exit_error(MSG_ERR_OPEN_FILE, TRUE);
}
