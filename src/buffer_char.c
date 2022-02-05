/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:24:26 by bzalugas          #+#    #+#             */
/*   Updated: 2022/02/05 09:57:15 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

t_buffer_char	*buffer_char_new(char content)
{
	t_buffer_char	*new;

	new = malloc(sizeof(t_buffer_char));
	if (!new)
		return (NULL);
	new->c = content;
	new->next = NULL;
	return (new);
}

t_buffer_char	*buffer_char_last(t_buffer_char *first)
{
	t_buffer_char	*tmp;

	tmp = first;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	buffer_char_size(t_buffer_char *first)
{
	int				i;
	t_buffer_char	*tmp;

	tmp = first;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	buffer_char_add(t_buffer_char **first, t_buffer_char *new)
{
	t_buffer_char	*last;

	if (*first)
	{
		last = buffer_char_last(*first);
		last->next = new;
	}
	else
		*first = new;
}

void	buffer_char_clear(t_buffer_char **first)
{
	t_buffer_char	*tmp;

	while (*first)
	{
		tmp = (*first)->next;
		free(*first);
		*first = tmp;
	}
	*first = NULL;
}
