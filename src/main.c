/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/10 16:45:35 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d		cub3d;

	invalid_args(&cub3d, argc, argv);
	init(argv, &cub3d);
	get_data(&cub3d);
	loop(&cub3d);
	destroy_all(&cub3d);
	return (EXIT_SUCCESS);
}
