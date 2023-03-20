/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:01:34 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/20 19:50:23 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define MSG_ERROR "Error\n"
# define MSG_USAGE "\n---Usage---\n./cub3d map.cub <path_to_levels>. \
\nExample: \"./cub3D assets/maps/walls.cub assets/maps/levels\n\""
# define MSG_FEW_ARGS "\tToo few arguments"
# define MSG_MANY_ARGS "\tToo many arguments"
# define MSG_INVALID_FILE "\tFile is invalid\n"
# define MSG_INVALID_FILE_FORMAT "\tFile format is invalid\n"
# define MSG_ERR_FILENAME "\tMap filename or path is invalid. \
Please ensure it is on the correct path and has a \".cub\" extension."
# define MSG_ERR_MLX_INIT "\tError at mlx init. Please try again\n"
# define MSG_ERR_OPEN_FILE "\tMap has wrongs permissions or doesn't exist\n"
# define MSG_ERR_TYPE_ID "\tInvalid floor or ceiling"
# define MSG_ERR_EMPTY_FILE "\tThe file is empty"
# define MSG_ERR_COLOR "\tColor value must be in the range of 0-255"
# define MSG_ERR_NO_PLAYER "Player not found in the map"
# define MSG_ERR_TWO_PLAYERS "Multiple players found in the map"
# define MSG_ERR_UNEXPECTED_CHAR "\tUnexpected character found in the map"
# define MSG_ERR_MAP_BORDER "\tThe map has no enclosing borders"
# define MSG_ERR_MISSING_RGB "\tMissing RGB color values"
# define MSG_ERR_LEVEL_FILE "\tThe file \"level\" in assets/maps/ \
is missing or incorrect"
# define MSG_ERR_EMPY_LEVEL_FILE "\tfile \"level\" is empty"
# define MSG_ERR_MISSING_MENU "\tthe image of the menu is missing at the \
location \"./assets/images/\". Please contact the game \
developers ETOMIYOS and/or MTOMOMIT"
# define MSG_ERR_IS_DIR "\tthe path for the level is a directory"
# define MSG_ERR_FILE_NAME "\tone of the maps at the level file is incorrect"

#endif
