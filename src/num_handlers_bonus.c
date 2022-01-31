/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handlers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:05:28 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/31 18:52:37 by bzalugas         ###   ########.fr       */
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
		hexa = ft_base_convert(pointer, "0123456789", "0123456789ABCDEF");
	else
		hexa = ft_base_convert(pointer, "0123456789", "0123456789abcdef");
	free(pointer);
	return (hexa);
}

void	handle_unsigned(unsigned n, t_flags *flags, t_buffer *buf)
{
	char	*num;

	num = ft_utoa(n);
	format_num(num, flags, buf);
	if (num)
		free(num);
	/* size_t	len; */
	/* char	*num; */

	/* num = ft_utoa(n); */
	/* len = ft_strlen(num); */
	/* if (num[0] && num[0] == '0' && flags->dot && flags->precision == 0) */
	/* { */
	/* 	num = ft_substr_free(num, 1, 1, 1); */
	/* 	len = 0; */
	/* } */
	/* if (flags->dot && flags->precision > len) */
	/* 	len += add_zeros_buf(flags->precision - len, buf); */
	/* if (flags->zero && flags->padding > len) */
	/* 	len += add_zeros_buf(flags->padding - len, buf); */
	/* else if (flags->min_field && flags->padding > len) */
	/* 	len += add_spaces_buf(flags->padding - len, buf); */
	/* buffer_add_str(buf, num, 0, -1); */
	/* if (flags->minus && flags->padding > len) */
	/* 	len += add_spaces_buf(flags->padding - len, buf); */
	/* free(num); */
}

void	handle_decimal(int n, t_flags *flags, t_buffer *buf)
{
	char	*num;

	num = ft_itoa(n);
	format_num(num, flags, buf);
	if (num)
		free(num);
	/* size_t		len; */
	/* char		*num; */

	/* num = ft_utoa(ft_abs(n)); */
	/* len = ft_strlen(num) + (n < 0 && !flags->dot); */
	/* if (num[0] && num[0] == '0' && flags->dot && flags->precision == 0) */
	/* { */
	/* 	num = ft_substr_free(num, 1, 1, 1); */
	/* 	len = 0; */
	/* } */
	/* if (flags->min_field && flags->padding > len) */
	/* 	len += add_spaces_buf(flags->padding - len, buf); */
	/* if (n < 0 && len++) */
	/* 	buffer_add_char(buf, '-'); */
	/* if (flags->dot && flags->precision > len) */
	/* 	len += add_zeros_buf(flags->precision - len, buf); */
	/* else if (flags->zero && flags->padding > len) */
	/* 	len += add_zeros_buf(flags->padding - len, buf); */
	/* buffer_add_str(buf, num, 0, -1); */
	/* if (flags->minus && flags->padding > len) */
	/* 	len += add_spaces_buf(flags->padding - (len + (n < 0)), buf); */
	/* free(num); */
}

void	handle_hexa(unsigned int n, t_flags *flags, t_buffer *buf)
{
	char	*hex;

	/* hex = NULL; */
	hex = pointer_to_hexa(n, (flags->conversion - 'x'));
	format_num(hex, flags, buf);
	if (hex)
		free(hex);
	/* char	*hexa; */
	/* char	*pre; */
	/* size_t	len; */

	/* pre = "0x"; */
	/* if (flags->conversion == 'X') */
	/* 	pre = "0X"; */
	/* hexa = NULL; */
	/* hexa = pointer_to_hexa(n, (flags->conversion - 'x')); */
	/* len = ft_strlen(hexa); */
	/* if (hexa[0] && hexa[0] == '0' && flags->dot && flags->precision == 0) */
	/* { */
	/* 	hexa = ft_substr_free(hexa, 1, 1, 1); */
	/* 	len = 0; */
	/* } */
	/* if (flags->dot && flags->precision > len) */
	/* 	len += add_zeros_buf(flags->precision - len, buf); */
	/* else if (flags->zero && flags->padding > len) */
	/* 	len += add_zeros_buf(flags->padding - len, buf); */
	/* else if (flags->min_field && flags->padding > len) */
	/* 	len += add_spaces_buf(flags->padding - len, buf); */
	/* if (hexa && flags->hashtag) */
	/* 	buffer_add_str(buf, pre, 0, 2); */
	/* buffer_add_str(buf, hexa, 0, -1); */
	/* if (flags->minus && flags->padding > len) */
	/* 	len += add_spaces_buf(flags->padding - len, buf); */
	/* free(hexa); */
}

void	handle_pointer(unsigned long p, t_flags *flags, t_buffer *buf)
{
	char		*hexa;
	size_t		len;

	hexa = pointer_to_hexa(p, 0);
	hexa = ft_strjoin_free("0x", hexa, 0, 1);
	len = ft_strlen(hexa);
	if (flags->min_field && flags->padding > len)
		len += add_spaces_buf(flags->padding - len, buf);
	buffer_add_str(buf, hexa, 0, -1);
	if (flags->minus && flags->padding > len)
		len += add_spaces_buf(flags->padding - len, buf);
	free(hexa);
}
