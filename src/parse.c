/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/22 11:59:54 by mtomomit         ###   ########.fr       */
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

void	invalid_args(int argc, char **argv)
{
	if (argc < 2)
		exit_error(MSG_FEW_ARGS, TRUE);
	if (argc > 2)
		exit_error(MSG_MANY_ARGS, TRUE);
	if (is_valid_file_extension(argv[1]) == FALSE)
		exit_error(MSG_INVALID_MAP, TRUE);
}
