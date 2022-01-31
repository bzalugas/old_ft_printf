/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:13 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/31 22:22:17 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include "../libft/libft.h"

typedef struct s_buffer_char
{
	char					c;
	struct s_buffer_char	*next;
}				t_buffer_char;

typedef struct s_buffer
{
	t_buffer_char	*first;
}				t_buffer;

/*					BUFFER_CHAR					*/

t_buffer_char	*buffer_char_new(char content);
t_buffer_char	*buffer_char_last(t_buffer_char *first);
int				buffer_char_size(t_buffer_char *first);
void			buffer_char_add(t_buffer_char **first, t_buffer_char *new);
void			buffer_char_clear(t_buffer_char **first);

/*					BUFFER						*/

t_buffer		*buffer_new(void);
void			buffer_close(t_buffer **buf);
void			buffer_add_char(t_buffer *buf, char c);
void			buffer_add_str(t_buffer *buf, const char *str, int start,
					int length);
size_t			buffer_add_chars(t_buffer *buf, char c, size_t len);
int				buffer_size(t_buffer *buf);
size_t			buffer_print_fd(t_buffer *buf, int fd);

#endif
