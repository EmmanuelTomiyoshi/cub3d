/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/22 11:09:23 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *msg, int usage)
{
	printf(MSG_ERROR);
	printf("%s\n", msg);
	if (usage)
		printf(MSG_USAGE);
	exit(EXIT_FAILURE);
}

void	invalid_args(int argc, char **argv)
{
	if (argc < 2)
		exit_error(MSG_FEW_ARGS, 1);
	if (argc > 2)
		exit_error(MSG_MANY_ARGS, 1);
	if (is_valid_file_extension(argv[1]) == FALSE)
		exit_error(MSG_INVALID_MAP, 1);
}
