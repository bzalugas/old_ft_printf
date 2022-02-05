/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:03:16 by bzalugas          #+#    #+#             */
/*   Updated: 2022/02/05 09:57:07 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void	buffer_add_char(t_buffer *buf, char c)
{
	t_buffer_char	*new_char;

	if (!buf)
		return ;
	new_char = buffer_char_new(c);
	if (!buf->first)
		buf->first = new_char;
	else
		buffer_char_add(&buf->first, new_char);
}

void	buffer_add_str(t_buffer *buf, const char *str, int start, int length)
{
	t_buffer_char	*new_char;
	int				strlen;
	int				i;

	strlen = ft_strlen(str);
	if (!buf || !str || length + start > strlen)
		return ;
	if (length == -1)
		length = strlen;
	i = start;
	while (i - start < length)
	{
		new_char = buffer_char_new(str[i]);
		if (!buf->first)
			buf->first = new_char;
		else
			buffer_char_add(&buf->first, new_char);
		i++;
	}
}

size_t	buffer_add_chars(t_buffer *buf, char c, size_t len)
{
	unsigned int	i;

	i = 0;
	while (++i < len + 1)
		buffer_add_char(buf, c);
	return (i - 1);
}
