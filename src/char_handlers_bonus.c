/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:06:11 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/28 11:56:55 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	handle_char(int c, t_flags *flags, t_buffer *buf)
{
	char		character = c;
	unsigned	i;

	i = flags->min_padding;
	if (flags->min_field && !flags->minus && flags->min_padding > 1)
		while (--i > 0)
			buffer_add_char(buf, ' ');
	buffer_add_char(buf, character);
	i = flags->min_padding;
	if (flags->minus && flags->min_padding > 1)
		while (--i > 0)
			buffer_add_char(buf, ' ');

}

void	handle_string(const char *str, t_flags *flags, t_buffer *buf)
{
	size_t		length;
	unsigned	i;

	length = ft_strlen(str);
	if (flags->dot)
		length = flags->precision;
	if (!str)
		str = "(null)";
	i = flags->min_padding + 1;
	if (flags->min_field && !flags->minus && flags->min_padding > length)
		while (--i > length)
			buffer_add_char(buf, ' ');
	buffer_add_str(buf, str, 0, length);
	i = flags->min_padding + 1;
	if (flags->minus && flags->min_padding > length)
		while(--i > length)
			buffer_add_char(buf, ' ');
}
