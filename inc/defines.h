/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:28:28 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 12:30:09 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "cub3d.h"

# define WIDTH 1200
# define HEIGHT 900

void	init(t_cub3d *c);
void	invalid_args(int argc);
void	destroy_all(t_cub3d *c);

#endif