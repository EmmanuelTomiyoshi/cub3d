/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:01:34 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/19 13:26:40 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define MSG_ERROR "Error\n"
# define MSG_USAGE "\n#Usage\n\t./cub3d filename.cub \
<path_for_the_level_file>\n"
# define MSG_FEW_ARGS "\t#Too few arguments"
# define MSG_MANY_ARGS "\tToo many arguments"
# define MSG_INVALID_FILE "\tFile is invalid\n"
# define MSG_INVALID_FILE_FORMAT "\tFile format is invalid\n"
# define MSG_ERR_FILENAME "\tMap filename or path is invalid"
# define MSG_ERR_MLX_INIT "\tError at mlx init. Please try again\n"
# define MSG_ERR_OPEN_FILE "\tMap has wrongs permissions or doesn't exist\n"
# define MSG_ERR_TYPE_ID "\tinvalid floor or ceiling"
# define MSG_ERR_EMPTY_FILE "\tthe file is empty"
# define MSG_ERR_COLOR "\tcolor value must be in the range of 0-255"
# define MSG_ERR_NO_PLAYER "\tPlayer not found in the map"
# define MSG_ERR_TWO_PLAYERS "\tMultiple players found in the map"
# define MSG_ERR_UNEXPECTED_CHAR "\tUnexpected charactere found in the map"
# define MSG_ERR_MAP_BORDER "\tThe map has no enclosing borders"
# define MSG_ERR_MISSING_RGB "\tmissing RGB color values"
# define MSG_ERR_LEVEL_FILE "\tthe path for the \"levels\" file \
is incorrect. Please ensure you are inputing a valid file"
# define MSG_ERR_EMPY_LEVEL_FILE "\tfile \"level\" is empty"
# define MSG_ERR_MISSING_MENU "\tthe image of the menu is missing at the \
location \"./assets/images/\". Please contact the game \
developers ETOMIYOS and/or MTOMOMIT"
# define MSG_ERR_FLAG_LEVEL "\tWrong flag level. Did you mean \
\'--levels=yes\' ?"
# define MSG_ERR_IS_DIR "\tthe path for the level is a directory"
# define FLAG_LEVEL "--levels=yes"

#endif
