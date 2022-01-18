/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:13 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/18 18:03:37 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include "../libft/libft.h"

typedef struct	s_buffer_char
{
	char					c;
	struct s_buffer_char	*next;
}				t_buffer_char;

typedef struct	s_buffer
{
	t_buffer_char	*first;
}				t_buffer;

t_buffer_char	*buffer_char_new(char content);
t_buffer_char	*buffer_char_last(t_buffer_char *first);
int				buffer_char_size(t_buffer_char *first);
void			buffer_char_add(t_buffer_char **first, t_buffer_char *new);
void			buffer_char_clear(t_buffer_char **first);

t_buffer		*buffer_new();
void			buffer_close(t_buffer **buf);
void			buffer_add_char(t_buffer *buf, char c);
/* void			add_str_buffer(t_buffer *buf, char *str); */
int				buffer_size(t_buffer *buf);
void			buffer_print_fd(t_buffer *buf, int fd);

#endif
