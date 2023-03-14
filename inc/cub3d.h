/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:55 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 00:30:46 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "printf_colors.h"
# include "display_resolution.h"
# include "fonts.h"
# include "defines.h"
# include "messages.h"
# include "bresenham.h"
# include "keys.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/X.h>
# include "../libft/libft.h"

//destroy.c
void		destroy_all(t_cub3d *c);
void		free_array(char **array);
void		free_file_data(t_cub3d *c);

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
int			end_loop(t_cub3d *c);

//validations.c
t_bool		is_valid_file_extension(char *filename);

//get_data.c
void		get_data(t_cub3d *c);

//get_coordinates.c
int			is_coordinate(int c);
void		get_coordinates(char *line, int *i, int id, t_cub3d *c);

//get_colors.c
void		get_colors(char *line, int *i, int id, t_cub3d *c);
int			is_floor_or_ceiling(int c);

//map.c
void		init_map(t_cub3d *c, char *one_line);

//queue.c
t_queue		*queue_put(t_queue *f_queue, size_t m, size_t n);
t_queue		*queue_get(t_queue *f_queue, size_t *m, size_t *n);
int			queue_empty(t_queue *f_queue);
void		queue_clear(t_queue *f_queue);

//flood_fill.c
void		flood_fill(t_cub3d *c, size_t n, size_t i, size_t j);
void		verify_map(t_cub3d *c);
t_bool		verify_char(t_cub3d *c, size_t i, size_t j);
void		verify_surrounding(t_cub3d *c, t_queue *queue, size_t i, size_t j);

//map_utils.c
char		*ft_merge(char *str1, char *str2);
size_t		count_lines(t_cub3d *c);
void		verify_up(t_cub3d *c, t_queue *queue, size_t i, size_t j);

//get_player_data.c
void		get_player_data(t_cub3d *c, int x, int y);

//bresenham.c
void		bresenham(t_vector *point1, t_vector *point2, \
					t_cub3d *c, int color);

//mlx.c
void		my_pixel_put(t_image *img, int x, int y, int color);
int			get_rgb(int r, int g, int b);

///dda/init.c
void		init_dist_to_side(t_cub3d *c);
void		init_camera(t_cub3d *c);
void		init_raydir_and_delta(t_cub3d *c);
void		init_perpendicular(t_cub3d *c);

void	itorgb(int color, t_rgb *result);

///dda/dda.c
int			draw(t_cub3d *c);

//rotate.c
void		rotate_vector(t_vector *vector, double ang);

//key_handle.c
int			key_press(int keycode, t_cub3d *c);
int			key_release(int keycode, t_cub3d *c);

//movements.c
void		walk_left(t_cub3d *c);
void		walk_forward(t_cub3d *c);
void		walk_backwards(t_cub3d *c);
void		walk_right(t_cub3d *c);

//camera.c
void		look_left(t_cub3d *c);
void		look_right(t_cub3d *c);
void		change_camera_speed(double x, double y, t_cub3d *c);
void		camera_move(int keycode, double x, double y, t_cub3d *c);

void		blend(t_rgb fg, t_rgb bg, float opacity, t_rgb *result);

int			mouse_callback(int button, int x, int y, t_cub3d *c);
int			draw_button(t_button button, t_cub3d *c);

int			show_menu(t_cub3d *c);
void		dda(t_cub3d *c);
void		raycasting(t_cub3d *c, int pixel);
void		movements(t_cub3d *c);
void		camera(t_cub3d *c);

#endif
