/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handlers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:05:28 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/29 20:07:56 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

char	*pointer_to_hexa(unsigned long p, int upper_case)
{
	char	*pointer;
	char	*hexa;

	pointer = ft_utoa(p);
	hexa = NULL;
	if (upper_case)
		hexa = 	ft_base_convert(pointer, "0123456789", "0123456789ABCDEF");
	else
		hexa = ft_base_convert(pointer, "0123456789", "0123456789abcdef");
	free(pointer);
	return (hexa);
}

void	handle_unsigned(unsigned n, t_flags *flags, t_buffer *buf)
{
	size_t	len;
	char	*num;

	num = ft_utoa(n);
	len = ft_strlen(num);
	if (flags->dot && flags->precision > len)
		add_zeros_buf(flags->precision - len, buf);
	if (flags->zero && flags->min_padding > len)
		add_zeros_buf(flags->min_padding - len, buf);
	else if (flags->min_field && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	buffer_add_str(buf, num, 0, len);
	if (flags->minus && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	free(num);
}

void	handle_decimal(int n, t_flags *flags, t_buffer *buf)
{
	size_t		len;
	char		*num;

	num = ft_utoa(ft_abs(n));
	len = ft_strlen(num) + (n < 0 && !flags->dot);
	if (n < 0)
		buffer_add_char(buf, '-');
	if (flags->dot && flags->precision > len)
		add_zeros_buf(flags->precision - len, buf);
	else if (flags->zero && flags->min_padding > len)
		add_zeros_buf(flags->min_padding - len, buf);
	else if (flags->min_field && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	buffer_add_str(buf, num, 0, -1);
	if (flags->minus && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	free(num);
}

void	handle_hexa(unsigned int n, t_flags *flags, t_buffer *buf)
{
	int		upper_case;
	char	*hexa;
	char	*pre;
	size_t	len;

	upper_case = 0;
	pre = "0x";
	if (flags->conversion == 'X')
	{
		upper_case = 1;
		pre = "0X";
	}
	hexa = NULL;
	hexa = pointer_to_hexa(n, upper_case);
	len = ft_strlen(hexa);
	if (flags->dot && flags->precision > len)
		add_zeros_buf(flags->precision - len, buf);
	else if (flags->zero && flags->min_padding > len)
		add_zeros_buf(flags->min_padding - len, buf);
	else if (flags->min_field && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	if (hexa && flags->hashtag)
		buffer_add_str(buf, pre, 0, 2);
	buffer_add_str(buf, hexa, 0, len);
	if (flags->minus && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	free(hexa);
}

void	handle_pointer(unsigned long p, t_flags *flags, t_buffer *buf)
{
	char		*hexa;
	size_t		len;

	hexa = pointer_to_hexa(p, 0);
	hexa = ft_strjoin_free("0x", hexa, 0, 1);
	len = ft_strlen(hexa);
	if (flags->min_field && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	buffer_add_str(buf, hexa, 0, -1);
	if (flags->minus && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	free(hexa);
}
