/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:22:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/13 21:24:25 by etomiyos         ###   ########.fr       */
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
	t_bool	hover;
}	t_button;

typedef struct s_menu
{
	t_bool		active;
	t_button	fullscreen;
	t_button	crosshair;
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
}	t_player;

typedef struct s_line
{
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			dy;
	int			dx;
}	t_line;

typedef struct s_map
{
	int		fd;
	int		infos;
	int		f_color;
	int		c_color;
	int		cube1;
	int		cube2;
	t_rgb	c_cube1;
	t_rgb	c_cube2;
	t_rgb	floor;
	t_rgb	ceiling;
	char	*file;
	char	**map;
	char	*ea_path;
	char	*we_path;
	char	*so_path;
	char	*no_path;
}	t_map;

typedef struct s_image
{
	void		*image;
	void		*original;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_win
{
	void	*ptr;
	int		width;
	int		height;
}	t_win;

typedef struct s_mlx
{
	t_image		img;
	t_win		win;
	void		*ptr;
	int			screen_width;
	int			screen_height;
}	t_mlx;

typedef struct s_cub3d
{
	t_mlx		mlx;
	t_map		map;
	t_dda		dda;
	t_player	player;
	t_menu		menu;
	t_bool		hovering;
}	t_cub3d;

# define WIN_NAME "cub3d"
# define WIDTH 1080
# define HEIGHT 720
# define LEFT_CLICK 1
# define MOUSE_RELEASE 0
# define LIGHT_BLUE	10735345
# define DARK_BLUE 6330042
# define DARK_GREEN 2090042
# define RED_PANTONE 15087942
# define MENU_OPACITY 0.25

#endif
