/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:45:58 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/25 05:21:21 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_queue	*queue_put(t_queue *f_queue, size_t m, size_t n)
{
	t_queue	*new;
	t_queue	*temp;

	if (f_queue == NULL)
	{
		f_queue = (t_queue *)malloc(sizeof(t_queue) * 1);
		f_queue->m = m;
		f_queue->n = n;
		f_queue->next = NULL;
	}
	else
	{
		temp = f_queue;
		while (temp->next != NULL)
			temp = temp->next;
		new = (t_queue *)malloc(sizeof(t_queue) * 1);
		new->m = m;
		new->n = n;
		new->next = NULL;
		temp->next = new;
	}
	return (f_queue);
}

t_queue	*queue_get(t_queue *f_queue, size_t *m, size_t *n)
{
	t_queue	*temp;

	*m = f_queue->m;
	*n = f_queue->n;
	if (f_queue->next != NULL)
	{
		temp = f_queue->next;
		free(f_queue);
		return (temp);
	}
	else
	{
		free(f_queue);
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
