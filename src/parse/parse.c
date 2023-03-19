/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 15:52:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalid_args(int argc, char **argv, t_cub3d *c)
{
	check_argc(argc);
	if (argc == 3)
		check_argv_flag_levels(argv[2], c);
	else
		c->level.flag = FALSE;
}
