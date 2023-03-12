/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:22:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/12 16:41:04 by etomiyos         ###   ########.fr       */
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
	int			pixel;
	t_vector	line_size;
	t_hit		hit;
	t_vector	wall_pos;
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
	char	*file;
	char	**map;
	char	*ea_path;
	char	*we_path;
	char	*so_path;
	char	*no_path;
}	t_map;

typedef struct s_cub3d
{
	t_mlx		mlx;
	t_map		map;
	t_dda		dda;
	t_player	player;
}	t_cub3d;

# define WIN_NAME "cub3d"
# define WIDTH 1080
# define HEIGHT 720

#endif
