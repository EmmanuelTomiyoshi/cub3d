/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_colors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:08:34 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/14 23:50:34 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_COLORS_H
# define PRINTF_COLORS_H

//Regular text
# define PTF_BLACK   "\001\e[0;30m\002"
# define PTF_RED     "\001\e[0;31m\002"
# define PTF_GREEN   "\001\e[0;32m\002"
# define PTF_YELLOW  "\001\e[0;33m\002"
# define PTF_BLUE    "\001\e[0;34m\002"
# define PTF_MAGENTA "\001\e[0;35m\002"
# define PTF_CYAN    "\001\e[0;36m\002"
# define PTF_WHITE   "\001\e[0;37m\002"

//Regular underline text
# define PTF_UBLACK   "\001\e[4;30m\002"
# define PTF_URED     "\001\e[4;31m\002"
# define PTF_UGREEN   "\001\e[4;32m\002"
# define PTF_UYELLOW  "\001\e[4;33m\002"
# define PTF_UBLUE    "\001\e[4;34m\002"
# define PTF_UMAGENTA "\001\e[4;35m\002"
# define PTF_UCYAN    "\001\e[4;36m\002"
# define PTF_UWHITE   "\001\e[4;37m\002"

//Regular background
# define PTF_BLACKB   "\001\e[40m\002"
# define PTF_REDB     "\001\e[41m\002"
# define PTF_GREENB   "\001\e[42m\002"
# define PTF_YELLOWB  "\001\e[43m\002"
# define PTF_BLUEB    "\001\e[44m\002"
# define PTF_MAGENTAB "\001\e[45m\002"
# define PTF_CYANB    "\001\e[46m\002"
# define PTF_WHITEB   "\001\e[47m\002"

//High intensty background
# define PTF_BLACKHB   "\001\e[0;100m\002"
# define PTF_REDHB     "\001\e[0;101m\002"
# define PTF_GREENHB   "\001\e[0;102m\002"
# define PTF_YELLOWHB  "\001\e[0;103m\002"
# define PTF_BLUEHB    "\001\e[0;104m\002"
# define PTF_MAGENTAHB "\001\e[0;105m\002"
# define PTF_CYANHB    "\001\e[0;106m\002"
# define PTF_WHITEHB   "\001\e[0;107m\002"

//High intensty text
# define PTF_HBLACK   "\001\e[0;90m\002"
# define PTF_HRED     "\001\e[0;91m\002"
# define PTF_HGREEN   "\001\e[0;92m\002"
# define PTF_HYELLOW  "\001\e[0;93m\002"
# define PTF_HBLUE    "\001\e[0;94m\002"
# define PTF_HMAGENTA "\001\e[0;95m\002"
# define PTF_HCYAN    "\001\e[0;96m\002"
# define PTF_HWHITE   "\001\e[0;97m\002"

//Bold high intensity text
# define PTF_BHBLACK   "\001\e[1;90m\002"
# define PTF_BHRED     "\001\e[1;91m\002"
# define PTF_BHGREEN   "\001\e[1;92m\002"
# define PTF_BHYELLOW  "\001\e[1;93m\002"
# define PTF_BHBLUE    "\001\e[1;94m\002"
# define PTF_BHMAGENTA "\001\e[1;95m\002"
# define PTF_BHCYAN    "\001\e[1;96m\002"
# define PTF_BHWHITE   "\001\e[1;97m\002"

//Reset
# define PTF_RESET       "\001\e[0m\002"
# define PTF_CRESET      "\001\e[0m\002"
# define PTF_COLOR_RESET "\001\e[0m\002"

#endif