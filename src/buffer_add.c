/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:03:16 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 20:03:51 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

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
	i = start - 1;
	while (++i < length)
	{
		new_char = buffer_char_new(str[i]);
		if (!buf->first)
			buf->first = new_char;
		else
			buffer_char_add(&buf->first, new_char);
	}
}
