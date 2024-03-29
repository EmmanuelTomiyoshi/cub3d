/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:22:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/21 13:13:42 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "bresenham.h"

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
	t_bool	toggle;
}	t_button;

typedef struct s_image
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_image;

typedef struct s_menu
{
	float		width_ratio;
	float		height_ratio;
	t_bool		active;
	t_image		img;
	t_image		resize;
	t_button	fullscreen;
	t_button	quit;
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
	int			pixel;
	double		perpendicular;
	t_hit		hit;
	t_vector	delta;
	t_vector	to_side;
	t_vector	step;
	t_vector	raydir;
	t_vector	line_size;
	t_vector	wall_pos;
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
	int		width;
	int		height;
	char	**map;
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

typedef struct s_argb
{
	int	a;
	int	r;
	int	g;
	int	b;
	int	argb;
}	t_argb;

typedef struct s_map
{
	int			fd;
	int			infos;
	int			c_color;
	int			f_color;
	t_rgb		ceiling;
	t_rgb		floor;
	char		*file;
	char		**map;
	char		*ea_path;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	t_texture	ea_tex;
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_player	player;
	t_minimap	minimap;
}	t_map;

typedef struct s_levels
{
	char	**files;
	char	*temp;
	int		count;
	t_bool	flag;
	char	*file_path;
	t_map	*name;
}	t_levels;

typedef struct s_keyhandle
{
	t_bool	move_left;
	t_bool	move_right;
	t_bool	move_forward;
	t_bool	move_backwards;
	t_bool	look_right;
	t_bool	look_left;
	t_bool	run;
	float	speed;
}	t_keyhandle;

typedef struct s_toggle
{
	t_bool	animate;
	t_bool	distortion;
	t_bool	light_mode;
	t_bool	mini_map;
}	t_toggle;

typedef struct s_cub3d
{
	t_mlx			mlx;
	t_map			map;
	t_dda			dda;
	t_draw			draw;
	t_temp			temp;
	t_toggle		state;
	t_menu			menu;
	t_keyhandle		key;
	t_queue			*f_queue;
	t_levels		level;
}	t_cub3d;

# define WIN_NAME 				"cub3d"
# define WIDTH 					1080
# define HEIGHT 				720
# define MENU_OPACITY 			0.25
# define BTN_FULLSCREEN			0
# define COLOR_THRESHOLD_MAX 	224
# define COLOR_THRESHOLD_MIN 	64
# define SPEED_THRESHOLD		0.12
# define ADD_LIGHT 				0.3
# define SUB_LIGHT 				-0.6
# define DEF_PLAYER_SPEED 		0.06
# define DEF_CAM_SPEED_X		2.4
# define DEF_CAM_SPEED_Y		357.6
# define BTN_X 					54
# define BTN_Y 					580
# define BTN_WIDTH 				180
# define BTN_HEIGHT 			72

#endif
