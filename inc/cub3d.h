/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:55 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 00:44:00 by etomiyos         ###   ########.fr       */
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

//destroy.c
void			destroy_all(t_cub3d *c);
void			free_array(char **array);
void			free_file_data(t_cub3d *c);

//exit.c
void			exit_error(char *msg, t_bool usage);

//init.c
void			init(char **argv, t_cub3d *c);

//loop.c
void			loop(t_cub3d *c);
void			destroy_level(t_cub3d *c);

void			get_map_content(t_map *map, char **one_line, t_cub3d *c);
void			get_colors_and_coordinates(t_map *map, t_cub3d *c);

void			update_level(t_cub3d *c);
void			level(t_cub3d *c);

//parse.c
void			invalid_args(int argc, char **argv, t_cub3d *c);

//render.c
int				render(t_cub3d *c);
int				end_loop(t_cub3d *c);

//validations.c
t_bool			is_valid_file_extension(char *filename);

int				brightness(t_cub3d *c);

int				handle_mouse(int x, int y, t_cub3d *c);

//get_data.c
void			get_data(t_cub3d *c);

//get_coordinates.c
int				is_coordinate(int c);
void			get_coordinates(t_map *map, int *i, int id, t_cub3d *c);

//get_colors.c
void			get_colors(t_map *map, int *i, int id, t_cub3d *c);
int				is_floor_or_ceiling(int c);

//map.c
void			get_map(t_map *map, t_cub3d *c, char *one_line);
void			destroy_coordinates(t_map *map);
void			destroy_file(t_map *map, t_cub3d *c);

//queue.c
t_queue			*queue_put(size_t m, size_t n, t_cub3d *c);
t_queue			*queue_get(size_t *m, size_t *n, t_cub3d *c);
int				queue_empty(t_queue *f_queue);
void			queue_clear(t_queue *f_queue);
size_t			count_lines(t_map *map);

//flood_fill.c
void			flood_fill(t_map *map, t_cub3d *c, size_t i, size_t j);
void			verify_map(t_map *map, t_cub3d *c);
t_bool			verify_char(t_map *map, size_t i, size_t j);
void			verify_surrounding(t_map *map, t_cub3d *c, size_t i, size_t j);

//map_utils.c
char			*ft_merge(char *str1, char *str2);
void			verify_up(t_map *map, size_t i, size_t j, t_cub3d *c);
void			change_brightness(t_cub3d *c);
void			destroy_texture(t_image	tex, t_cub3d *c);

//get_player_data.c
void			get_player_data(t_map *map, t_cub3d *c, int x, int y);

//bresenham.c
void			bresenham(t_vector *point1, t_vector *point2, \
					t_cub3d *c, int color);

//mlx.c
void			my_pixel_put(t_image *img, int x, int y, int color);
int				get_rgb(int r, int g, int b);

///dda/init.c
void			init_dist_to_side(t_cub3d *c);
void			init_camera(t_map *map, t_cub3d *c);
void			init_raydir_and_delta(t_cub3d *c);
void			init_perpendicular(t_cub3d *c);

unsigned int	return_color(t_image *img, int x, int y);

void			player_speed(t_cub3d *c);

void			itorgb(int color, t_rgb *result);

///dda/dda.c
int				draw(t_cub3d *c);

void			get_level_info(t_cub3d *c);

//rotate.c
void			rotate_vector(t_vector *vector, double ang);
void			get_texture(t_map *map, t_cub3d *c);

//key_handle.c
int				key_press(int keycode, t_cub3d *c);
int				key_release(int keycode, t_cub3d *c);

int				change_win_size(t_cub3d *c);

//camera.c
void			camera(t_map *map, t_cub3d *c);
void			look_left(t_map *map);
void			look_right(t_map *map);
void			camera_speed(double x, double y, t_cub3d *c);
void			camera_move(int keycode, double x, double y, t_cub3d *c);

//color/conversions.c
void			intorgb(int *r, int *g, int *b, unsigned int *color);
void			blend(t_rgb fg, t_rgb bg, float opacity, t_rgb *result);
unsigned int	blending(unsigned int color, float opacity, t_cub3d *c);

//color/brightness.c
unsigned int	increase_brightness(unsigned int *color, float opacity);
unsigned int	decrease_brightness(unsigned int *color, float opacity);
void			square_colors(t_cub3d *c);
int				mouse_callback(int button, int x, int y, t_cub3d *c);
int				draw_button(t_button button, t_image img);

void			show_menu(t_cub3d *c);
void			dda(t_cub3d *c);
void			raycasting(t_cub3d *c, int pixel);
void			movements(t_map *map, t_cub3d *c);
void			walk_left(t_map *map, t_cub3d *c);
void			walk_forward(t_map *map, t_cub3d *c);
void			walk_backwards(t_map *map, t_cub3d *c);
void			walk_right(t_map *map, t_cub3d *c);

//button/button_utils.c
void			get_btn_pos(t_button *btn, int x, int y);
void			get_btn_size(t_button *btn, int width, int height);

//draw/draw.c
void			pixel(t_cub3d *c);
void			animate_sprite(t_cub3d *c);
void			draw_texture(t_cub3d *c, int pixel);

//minimap/minimap.c
void			draw_minimap(t_cub3d *c);
void			get_minimap(t_map *map);

//hooks/key_handle_utils.c
void			distortion(t_cub3d *c);
void			animate(t_cub3d *c);
void			show_minimap(t_cub3d *c);

void			iall(t_cub3d *c);

void			new_mlx(t_cub3d *c);

#endif
