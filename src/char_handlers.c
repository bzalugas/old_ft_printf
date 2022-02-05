/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:06:11 by bzalugas          #+#    #+#             */
/*   Updated: 2022/02/05 11:04:45 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(int c, t_flags *flags, t_buffer *buf)
{
	if (flags->min_field && flags->padding > 1)
		buffer_add_chars(buf, ' ', flags->padding - 1);
	buffer_add_char(buf, c);
	if (flags->minus && flags->padding > 1)
		buffer_add_chars(buf, ' ', flags->padding - 1);
}

void	handle_string(const char *str, t_flags *flags, t_buffer *buf)
{
	size_t		len;

	if (!str && (OS & APPLE || !flags->dot || flags->precision > 5))
		str = "(null)";
	len = ft_strlen(str);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	if (flags->min_field && flags->padding > len)
		buffer_add_chars(buf, ' ', flags->padding - len);
	buffer_add_str(buf, str, 0, len);
	if (flags->minus && flags->padding > len)
		buffer_add_chars(buf, ' ', flags->padding - len);
}
