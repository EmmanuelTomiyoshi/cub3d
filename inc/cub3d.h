/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:55 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 11:48:51 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//headers
# include "bresenham.h"
# include "colors.h"
# include "defines.h"
# include "fonts.h"
# include "keys.h"
# include "messages.h"
# include "printf_colors.h"

//libraries
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/X.h>
# include "../libs/libft/libft.h"

//algorithms/bresenham.c
void			bresenham(t_vector *point1, t_vector *point2, \
					t_cub3d *c, int color);

//algorithms/flood_fill.c
void			flood_fill(t_map *map, t_cub3d *c, size_t i, size_t j);
void			verify_map(t_map *map, t_cub3d *c);
t_bool			verify_char(t_map *map, size_t i, size_t j);
void			verify_surrounding(t_map *map, t_cub3d *c, size_t i, size_t j);

//algorithms/dda.c
void			dda(t_cub3d *c);
void			raycasting(t_cub3d *c, int pixel);

//algorithms/init.c
void			init_dist_to_side(t_cub3d *c);
void			init_camera(t_map *map, t_cub3d *c);
void			init_raydir_and_delta(t_cub3d *c);
void			init_perpendicular(t_cub3d *c);

//algorithms/queue.c
t_queue			*queue_put(size_t m, size_t n, t_cub3d *c);
t_queue			*queue_get(size_t *m, size_t *n, t_cub3d *c);
int				queue_empty(t_queue *f_queue);
void			queue_clear(t_queue *f_queue);

//button/button_utils.c
void			get_btn_pos(t_button *btn, int x, int y);
void			get_btn_size(t_button *btn, int width, int height);

//button/button.c
int				mouse_callback(int button, int x, int y, t_cub3d *c);
int				draw_button(t_button button, t_image img);
void			animate_sprite(t_cub3d *c);

//color/brightness.c
int				brightness(t_cub3d *c);
unsigned int	increase_brightness(unsigned int *color, float opacity);
unsigned int	decrease_brightness(unsigned int *color, float opacity);
void			change_brightness(t_cub3d *c);

//color/conversions.c
void			blend(t_rgb fg, t_rgb bg, float opacity, t_rgb *result);
unsigned int	blending(unsigned int color, float opacity, t_cub3d *c);

//color/int_to_rgb.c
void			intorgb(int *r, int *g, int *b, unsigned int *color);
void			itorgb(int color, t_rgb *result);

//destroy/destroy_level.c
void			destroy_level(t_cub3d *c);
void			destroy_file(t_map *map, t_cub3d *c);

//destroy/destroy.c
void			destroy_all(t_cub3d *c);
void			destroy_texture(t_image	tex, t_cub3d *c);
void			destroy_coordinates(t_map *map);

//destroy/exit.c
void			exit_error(char *msg, t_bool usage);

//draw/draw.c
int				draw(t_cub3d *c);

//draw/texture.c
unsigned int	return_color(t_image *img, int x, int y);
void			draw_texture(t_cub3d *c, int pixel, t_texture *tex);

//get_data/colors.c
void			get_colors(t_map *map, int *i, int id, t_cub3d *c);

//get_data/coordinates.c
void			get_coordinates(t_map *map, int *i, int id, t_cub3d *c);

//get_data/data.c
void			get_colors_and_coordinates(t_map *map, t_cub3d *c);
void			get_map_content(t_map *map, char **one_line, t_cub3d *c);
void			get_data(t_cub3d *c);

//get_data/levels.c
void			get_level_colors_and_coordinates(t_cub3d *c);
void			get_level_fd(t_cub3d *c);

//get_data/get_player_data.c
void			get_player_data(t_map *map, t_cub3d *c, int x, int y);

//get_data/texture.c
void			get_texture(t_map *map, t_cub3d *c);

//get_data/get_coordinates.c
int				is_coordinate(int c);
int				is_floor_or_ceiling(int c);

#endif
