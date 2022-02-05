/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:04:18 by bzalugas          #+#    #+#             */
/*   Updated: 2022/02/05 09:58:07 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	make_num(char *num, t_flags *flags)
{
	size_t	len_num;

	len_num = ft_strlen(num) - (num[0] == '-');
	if (num[0] == '0' && flags->dot && flags->precision == 0)
		len_num = 0;
	if ((flags->dot || flags->zero) && flags->precision > len_num)
		flags->precision -= len_num + (flags->zero && num[0] == '-')
			+ (flags->zero && ((flags->space || flags->plus) && num[0] != '-'));
	else
		flags->precision = 0;
	return (len_num);
}

void	format_num(char *num, t_flags *flags, t_buffer *buf)
{
	size_t	len;
	size_t	len_num;

	len_num = make_num(num, flags);
	len = len_num + (len_num > 0 && num[0] == '-') + flags->precision;
	if (flags->plus && num[0] != '-')
		len += buffer_add_chars(buf, '+', 1);
	if (flags->space && num[0] != '-')
		len += buffer_add_chars(buf, ' ', 1);
	if (flags->min_field && flags->padding > len)
		len += buffer_add_chars(buf, ' ', flags->padding - len);
	if (num[0] == '-')
		buffer_add_char(buf, '-');
	if ((flags->conversion == 'x' || flags->conversion == 'X') && flags->sharp
		&& num[0] != '0')
	{
		buffer_add_char(buf, '0');
		buffer_add_char(buf, flags->conversion);
	}
	buffer_add_chars(buf, '0', flags->precision);
	buffer_add_str(buf, num, 0 + (num[0] == '-'), len_num);
	if (flags->minus && flags->padding > len)
		buffer_add_chars(buf, ' ', flags->padding - len);
}
