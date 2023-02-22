/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:07:55 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 21:32:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "printf_colors.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"

# define WIDTH 1200
# define HEIGHT 900
# define MSG_ERROR "Error\n"
# define MSG_USAGE "\n---Usage---\n./cub3d <filename.cub>\n"
# define MSG_FEW_ARGS "Too few arguments"
# define MSG_MANY_ARGS "Too many arguments"
# define MSG_INVALID_MAP "Map filename is invalid"
# define MSG_ERR_MLX_INIT "Error at mlx init. Please try again\n"

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

typedef struct s_cub3d
{
	t_image		img;
	char		*map;
	void		*mlx;
	void		*win;
}	t_cub3d;

//destroy.c
void	destroy_all(t_cub3d *c);

//init.c
void	init(char **argv, t_cub3d *c);

//loop.c
void	loop(t_cub3d *c);

//parse.c
void	invalid_args(int argc, char **argv);
void	exit_error(char *msg, t_bool usage);

//render.c
int		render(t_cub3d *c);

//validations.c
t_bool	is_valid_file_extension(char *filename);

#endif
