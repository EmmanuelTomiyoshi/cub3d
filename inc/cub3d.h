/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:55 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/23 02:23:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "printf_colors.h"
# include "fonts.h"
# include "defines.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"

//destroy.c
void		destroy_all(t_cub3d *c);
void		free_array(char **array);
void		free_file_data(t_file_data *file_data);

//exit.c
void		exit_error(char *msg, t_bool usage);

//init.c
void		init(char **argv, t_cub3d *c);

//loop.c
void		loop(t_cub3d *c);

//parse.c
void		invalid_args(t_cub3d *c, int argc, char **argv);


//render.c
int			render(t_cub3d *c);

//validations.c
t_bool		is_valid_file_extension(char *filename);

//color.c
int			get_color(t_file_data *file_data, char **splited_line);
void		free_split(char **split);

//get_data.c
// t_file_data	*get_data(char *file);
void		ignore_spaces(char *line, int *i);
void		get_data(t_cub3d *c);

//get_coordinates.c
int			is_coordinate(int c);
void		get_coordinates(char *line, int *i, int id, t_cub3d *c);

//get_colors.c
void		get_colors(char *line, int *i, int id, t_cub3d *c);
int			is_floor_or_ceiling(int c);

#endif
