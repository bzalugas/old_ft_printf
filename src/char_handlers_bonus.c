/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:06:11 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/31 21:21:40 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	handle_char(int c, t_flags *flags, t_buffer *buf)
{
	if (flags->min_field && flags->padding > 1)
		add_chars_buf(flags->padding - 1, buf, ' ');
	buffer_add_char(buf, c);
	if (flags->minus && flags->padding > 1)
		add_chars_buf(flags->padding - 1, buf, ' ');
}

void	handle_string(const char *str, t_flags *flags, t_buffer *buf)
{
	size_t		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	if (flags->min_field && flags->padding > len)
		add_chars_buf(flags->padding - len, buf, ' ');
	buffer_add_str(buf, str, 0, len);
	if (flags->minus && flags->padding > len)
		add_chars_buf(flags->padding - len, buf, ' ');
}
