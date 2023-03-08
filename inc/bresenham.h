/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:40:49 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/08 19:41:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

typedef struct s_queue
{
	size_t			m;
	size_t			n;
	struct s_queue	*next;
}	t_queue;

typedef struct s_point
{
	double		x;
	double		y;
}	t_point;

#endif
