/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:25:41 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 13:41:23 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_coordinate(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (-1);
}

int	is_floor_or_ceiling(int c)
{
	if (c == 'C' || c == 'F')
		return (c);
	return (-1);
}

void	check_color_value(char **rgb, t_cub3d *c)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (!rgb[i][0])
		{
			ft_free_array(rgb);
			destroy_all(c);
			exit_error(MSG_ERR_MISSING_RGB, FALSE);
		}
		i++;
	}
}

void	verify_rgb(char **rgb, char *line, int *i, t_cub3d *c)
{
	if (ft_isdigit(line[*i]) == FALSE && line[*i] != ','
		&& line[*i] != '\n')
	{
		rgb_error(rgb, c);
	}
}