/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:30:36 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/29 16:27:50 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include "buffer.h"
# include <stdarg.h>
# define CONVERT_SYMBOL '%'
# define CONVERSION "cspdiuxX%"
# define FLAGS "-0.# +"

typedef struct s_flags
{
	unsigned	min_field : 1;
	unsigned	minus : 1;
	unsigned	min_padding;
	unsigned	zero : 1;
	unsigned	dot : 1;
	unsigned	precision;
	unsigned	hashtag : 1;
	unsigned	space : 1;
	unsigned	plus : 1;
	char		conversion;
}				t_flags;

/*			FORMAT WITH FLAGS		*/

void	add_spaces_buf(size_t len, t_buffer *buf);

/*			FLAGS HANDLING			*/

void	flags_init(t_flags *flags);
size_t	put_min_field(const char *str, t_flags *flags);
size_t	put_minus(const char *str, t_flags *flags);
size_t	put_dot(const char *str, t_flags *flags);

/*			CONVERTERS				*/

char	*pointer_to_hexa(unsigned long p, int upper_case);

/*			HANDLERS				*/

void	handle_char(int c, t_flags *flags, t_buffer *buf);
void	handle_string(const char *str, t_flags *flags, t_buffer *buf);
void	handle_pointer(unsigned long p, t_flags *flags, t_buffer *buf);
void	handle_decimal(int n, t_flags *flags, t_buffer *buf);
void	handle_unsigned(unsigned int n, t_flags *flags, t_buffer *buf);
void	handle_hexa(unsigned int n, t_flags *flags, t_buffer *buf);

/*			MAIN FUNCTIONS			*/

size_t	put_flag(const char *str, t_flags *flags);
t_flags	find_flags(const char *str, size_t *forward);
int		convert(const char *str, va_list args, t_buffer *buf);
void	str_transform(const char *str, va_list args, t_buffer *buf);
int		ft_printf(const char *str, ...);

#endif
