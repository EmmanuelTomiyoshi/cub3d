/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:22:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/16 21:30:26 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdio.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_button
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color_active;
	int		color_normal;
	t_bool	toggle;
}	t_button;

typedef struct s_image
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_width;
	int			win_height;
}	t_image;

typedef struct s_menu
{
	t_image		img;
	t_bool		active;
	t_image		resize;
	t_button	fullscreen;
	t_button	quit;
	float		width_ratio;
	float		height_ratio;
}	t_menu;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_vector
{
	double		y;
	double		x;
}	t_vector;

typedef struct s_hit
{
	t_bool		hit;
	int			side;
}	t_hit;

typedef struct s_dda
{
	t_vector	delta;
	t_vector	to_side;
	t_vector	step;
	t_vector	raydir;
	t_vector	line_size;
	t_vector	wall_pos;
	t_hit		hit;
	int			pixel;
	double		perpendicular;
}	t_dda;

typedef struct s_camera
{
	t_vector	pixel;
	t_vector	plane;
	t_vector	speed;
}	t_camera;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
	t_camera	camera;
	t_bool		move_left;
	t_bool		move_right;
	t_bool		move_foward;
	t_bool		move_backwards;
	t_bool		look_right;
	t_bool		look_left;
	t_bool		run;
	float		speed;
}	t_player;

typedef struct s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	dy;
	int	dx;
}	t_line;

typedef struct s_win
{
	void	*ptr;
	int		width;
	int		height;
}	t_win;

typedef struct s_texture
{
	t_image	img;
	int		width;
	int		height;
}	t_texture;

typedef struct s_mlx
{
	t_texture	ea_tex;
	t_texture	so_tex;
	t_texture	no_tex;
	t_texture	we_tex;
	t_image		img;
	t_win		win;
	void		*ptr;
	int			screen_width;
	int			screen_height;
}	t_mlx;

typedef struct s_temp
{
	char	*line;
}	t_temp;

typedef struct s_minimap
{
	char	**map;
	int		width;
	int		height;
}	t_minimap;

typedef struct s_draw
{
	int				wall_line_height;
	int				start;
	int				end;
	int				tex_x;
	int				tex_y;
	double			wall_x;
	double			tex_pos;
	double			step;
	unsigned int	color;
}	t_draw;

typedef struct	s_argb
{
	int	a;
	int	r;
	int	g;
	int	b;
	int	argb;
}	t_argb;

typedef struct s_map
{
	int		fd;
	int		infos;
	int		f_color;
	int		c_color;
	t_rgb	floor;
	t_rgb	ceiling;
	char	*file;
	char	**map;
	char	*ea_path;
	char	*we_path;
	char	*so_path;
	char	*no_path;
}	t_map;

typedef	struct s_level
{
	t_map	circle;
	t_map	maze;
	t_map	perpendicular;
	t_map	random;
	t_map	room;
	t_map	walls;
	t_map	zigzag;
}	t_level;

typedef struct s_cub3d
{
	t_mlx		mlx;
	t_map		map;
	t_dda		dda;
	t_player	player;
	t_menu		menu;
	t_minimap	minimap;
	t_draw		draw;
	t_temp		temp;
	t_bool		distortion;
	t_bool		light_mode;
	t_bool		animate;
	t_bool		mini_map;
	t_level		level;
}	t_cub3d;

# define WIN_NAME 				"cub3d"
# define WIDTH 					1080
# define HEIGHT 				720
# define MENU_OPACITY 			0.25
# define BTN_FULLSCREEN			0
# define COLOR_THRESHOLD_MAX 	224
# define COLOR_THRESHOLD_MIN 	64
# define SPEED_THRESHOLD		0.16
# define ADD_LIGHT 				0.3
# define SUB_LIGHT 				-0.6
# define DEF_PLAYER_SPEED 		0.054
# define DEF_CAM_SPEED_X		1.2799
# define DEF_CAM_SPEED_Y		358.7201
# define BTN_X 					54
# define BTN_Y 					580
# define BTN_WIDTH 				180
# define BTN_HEIGHT 			72

#endif
