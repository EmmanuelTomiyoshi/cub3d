/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:45:58 by mtomomit          #+#    #+#             */
/*   Updated: 2023/03/18 09:58:37 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_queue	*queue_put(size_t m, size_t n, t_cub3d *c)
{
	t_queue	*new;
	t_queue	*temp;

	if (c->f_queue == NULL)
	{
		c->f_queue = (t_queue *)malloc(sizeof(t_queue) * 1);
		c->f_queue->m = m;
		c->f_queue->n = n;
		c->f_queue->next = NULL;
	}
	else
	{
		temp = c->f_queue;
		while (temp->next != NULL)
			temp = temp->next;
		new = (t_queue *)malloc(sizeof(t_queue) * 1);
		new->m = m;
		new->n = n;
		new->next = NULL;
		temp->next = new;
	}
	return (c->f_queue);
}

t_queue	*queue_get(size_t *m, size_t *n, t_cub3d *c)
{
	t_queue	*temp;

	*m = c->f_queue->m;
	*n = c->f_queue->n;
	if (c->f_queue->next != NULL)
	{
		temp = c->f_queue->next;
		free(c->f_queue);
		return (temp);
	}
	else
	{
		free(c->f_queue);
		return (NULL);
	}
}

int	queue_empty(t_queue *f_queue)
{
	if (f_queue != NULL)
		return (1);
	else
		return (0);
}

void	queue_clear(t_queue *f_queue)
{
	t_queue	*temp;
	t_queue	*temp2;

	if (f_queue->next != NULL)
	{
		temp = f_queue->next;
		temp2 = temp;
		free(f_queue);
		while (temp2->next != NULL)
		{
			temp = temp2->next;
			free(temp2);
			temp2 = temp;
		}
		free(temp);
	}
	else
		free(f_queue);
}
