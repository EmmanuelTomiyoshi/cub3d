/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:01:34 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 00:33:10 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define MSG_ERROR "Error\n"
# define MSG_USAGE "\n---Usage---\n./cub3d <filename.cub>\n"
# define MSG_FEW_ARGS "Too few arguments"
# define MSG_MANY_ARGS "Too many arguments"
# define MSG_INVALID_FILE "File is invalid\n"
# define MSG_INVALID_FILE_FORMAT "File format is invalid\n"
# define MSG_ERR_FILENAME "Map filename or path is invalid"
# define MSG_ERR_MLX_INIT "Error at mlx init. Please try again\n"
# define MSG_ERR_OPEN_FILE "Map has wrongs permissions or doesn't exist\n"
# define MSG_ERR_TYPE_ID "invalid coordinate/floor/ceiling"
# define MSG_ERR_EMPTY_FILE "the file is empty"
# define MSG_ERR_COLOR "color value must be in the range of 0-255"
# define MSG_ERR_NO_PLAYER "Player not found in the map"
# define MSG_ERR_TWO_PLAYERS "Multiple players found in the map"
# define MSG_ERR_UNEXPECTED_CHAR "Unexpected charactere found in the map"
# define MSG_ERR_MAP_BORDER "The map has no enclosing borders"

#endif
