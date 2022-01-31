/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:04:18 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/31 19:26:05 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

size_t	add_spaces_buf(size_t len, t_buffer *buf)
{
	unsigned int	i;

	i = 0;
	while (++i < len + 1)
		buffer_add_char(buf, ' ');
	return (i - 1);
}

size_t	add_zeros_buf(size_t len, t_buffer *buf)
{
	unsigned int	i;

	i = 0;
	while (++i < len + 1)
		buffer_add_char(buf, '0');
	return (i - 1);
}

void	format_num(char *num, t_flags *flags, t_buffer *buf)
{
	size_t	len;
	size_t	len_num;

	len_num = ft_strlen(num) - (num[0] == '-');
	if (num[0] == '0' && flags->dot && flags->precision == 0)
		len_num = 0;
	if ((flags->dot || flags->zero) && flags->precision > len_num)
		flags->precision -= len_num + (flags->zero && num[0] == '-');
	else
		flags->precision = 0;
	len = len_num + (len_num > 0 && num[0] == '-') + flags->precision;
	if (flags->min_field && flags->padding > len)
		len += add_spaces_buf(flags->padding - len, buf);
	if (num[0] == '-')
		buffer_add_char(buf, '-');
	add_zeros_buf(flags->precision, buf);
	if ((flags->conversion == 'x' || flags->conversion == 'X') && flags->sharp)
	{
		buffer_add_char(buf, '0');
		buffer_add_char(buf, flags->conversion);
	}
	buffer_add_str(buf, num, 0 + (num[0] == '-'), len_num);
	if (flags->minus && flags->padding > len)
		add_spaces_buf(flags->padding - len, buf);
	/* if (flags->min_field && flags->padding > len) */
	/* 	flags->padding -= len; */
	/* if (flags->minus && flags->padding > len) */
	/* 	flags->padding -= len; */

}
