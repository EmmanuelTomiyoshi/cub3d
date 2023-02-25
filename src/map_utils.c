/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 04:22:48 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/25 05:21:18 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_lines(t_cub3d *c)
{
	size_t	i;

	i = 0;
	while (c->map[i])
		i++;
	return (i);
}

char	*ft_merge(char *str1, char *str2)
{
	size_t	str1len;
	size_t	str2len;
	char	*line;
	size_t	i;
	size_t	o;

	str1len = 0;
	str2len = 0;
	if (str1[0])
		str1len = ft_strlen(str1);
	if (str2[0])
		str2len = ft_strlen(str2) + 1;
	line = (char *)malloc(sizeof(char) * (str1len + str2len));
	i = 0;
	o = 0;
	while (str1[o])
		line[i++] = str1[o++];
	o = 0;
	while (str2[o])
		line[i++] = str2[o++];
	line[i] = str2[o];
	free(str1);
	return (line);
}