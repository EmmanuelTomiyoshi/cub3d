/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:16:05 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/23 02:16:20 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *msg, t_bool usage)
{
	printf(MSG_ERROR);
	printf("%s\n", msg);
	if (usage == TRUE)
		printf(MSG_USAGE);
	exit(EXIT_FAILURE);
}
