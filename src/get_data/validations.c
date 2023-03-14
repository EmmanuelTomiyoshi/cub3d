/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:25:41 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 00:26:00 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
