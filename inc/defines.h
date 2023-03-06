/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:22:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/06 16:11:36 by mtomomit         ###   ########.fr       */
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

typedef struct s_image
{
	void		*image;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_file_data
{
	int		fd;
	int		f_color;
	int		c_color;
	int		infos;
	char	*ea_path;
	char	*we_path;
	char	*so_path;
	char	*no_path;
}	t_file_data;

typedef struct s_queue
{
	size_t			m;
	size_t			n;
	struct s_queue	*next;
}	t_queue;

typedef struct s_vector
{
	double		y;
	double		x;
}	t_vector;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
} t_player;

typedef struct s_cub3d
{
	t_image		img;
	t_file_data	*file_data;
	char		*map_file;
	char		**map;
	int			map_fd;
	void		*mlx;
	void		*win;
	t_player	player;
}	t_cub3d;

# define WIN_NAME "cub3d"
# define WIDTH 1200
# define HEIGHT 900

# define MSG_ERROR "Error\n"
# define MSG_USAGE "\n---Usage---\n./cub3d <filename.cub>\n"
# define MSG_FEW_ARGS "Too few arguments"
# define MSG_MANY_ARGS "Too many arguments"
# define MSG_INVALID_FILE "File is invalid\n"
# define MSG_INVALID_FILE_FORMAT "File format is invalid\n"
# define MSG_ERR_FILENAME "Map filename is invalid"
# define MSG_ERR_MLX_INIT "Error at mlx init. Please try again\n"
# define MSG_ERR_OPEN_FILE "Map has wrongs permissions or doesn't exist\n"
# define MSG_ERR_TYPE_ID "invalid coordinate/floor/ceiling"
# define MSG_ERR_COLOR "color value must be in the range of 0-255"
# define MSG_ERR_NO_PLAYER "Player not found in the map"
# define MSG_ERR_TWO_PLAYERS "Multiple players found in the map"
# define MSG_ERR_UNEXPECTED_CHAR "Unexpected charactere found in the map"
# define MSG_ERR_MAP_BORDER "The map has no enclosing borders"

#endif
