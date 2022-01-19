/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:40 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 17:15:22 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
/* #include "../includes/leaks_tester.h" */

t_buffer	*buffer_new(void)
{
	t_buffer		*new_buf;

	new_buf = malloc(sizeof(t_buffer));
	if (!new_buf)
		return (NULL);
	new_buf->first = NULL;
	return (new_buf);
}

/*
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
}*/

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

int	buffer_size(t_buffer *buf)
{
	if (buf && buf->first)
		return (buffer_char_size(buf->first));
	else if (buf)
		return (0);
	return (-1);
}

void	buffer_print_fd(t_buffer *buf, int fd)
{
	char			*str;
	int				i;
	t_buffer_char	*next_char;

	if (!buf)
		return ;
	str = malloc(sizeof(char) * buffer_size(buf) + 1);
	if (!str)
		return ;
	next_char = buf->first;
	i = 0;
	while (next_char && i < buffer_size(buf))
	{
		str[i++] = next_char->c;
		next_char = next_char->next;
	}
	str[i] = '\0';
	ft_putstr_fd(str, fd);
	free(str);
}

void	buffer_close(t_buffer **buf)
{
	buffer_char_clear(&(*buf)->first);
	free(*buf);
	*buf = NULL;
}
