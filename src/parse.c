/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 12:11:21 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	invalid_args(int argc)
{
	if (argc < 2)
		exit_error("Invalid args #1");
	if (argc > 2)
		exit_error("Invalid args #2");
}
