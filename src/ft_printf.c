/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:29:17 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/22 19:25:32 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	put_flag(char *str, t_flags *flags)
{
	if (str[0] == '-')
		flags->minus = 1;
	else if (str[0] == '0')
		flags->zero = 1;
	else if (str[0] == '.')
	{
		flags->dot = 1;
		flags->precision = ft_atoi(str + 1);
	}
	else if (str[0] == '#')
		flags->hashtag = 1;
	else if (str[0] == ' ')
		flags->space = 1;
	else if (str[0] == '+')
		flags->plus = 1;
	else
		flags->conversion = str[0];
}

t_flags	find_flags(const char *str)
{
	int		i;
	int		j;
	t_flags	flags;

	flags_init(&flags);
	i = -1;
	j = 0;
	while (FLAGS[++i])
	{
		if (str[j] == FLAGS[i])
		{
			put_flag(&FLAGS[i], &flags);
			i = -1;
			j++;
		}
	}
	i = 0;
	while (CONVERSION[i] && CONVERSION[i] != str[j])
		i++;
	if (CONVERSION[i] && CONVERSION[i] == str[j])
		put_flag(&CONVERSION[i], &flags);
	return (flags);
}

int	convert(const char *str, va_list args, t_buffer *buf)
{
	t_flags	flags;
	int		forward;

	flags = find_flags(str + 1);
	if (flags.conversion == 'c')
		handle_char(va_arg(args, int), buf);
	else if (flags.conversion == '%')
		handle_char('%', buf);
	else if (flags.conversion == 's')
		handle_string(va_arg(args, char *), &flags, buf);
	else if (flags.conversion == 'p')
		handle_pointer(va_arg(args,unsigned long), buf);
	/* else if (flags.conversion == 'd') */
	/* 	handle_decimal(va_arg(args, int), flags, buf); */
	/* else if (flags.conversion == 'i') */
	/* 	handle_int(va_arg(args, int),flags, buf); */
	/* else if (flags.conversion == 'u') */
	/* 	handle_u_decimal(va_arg(args, unsigned int), flags, buf); */
	else if (flags.conversion == 'x' || flags.conversion == 'X')
		handle_hexa(va_arg(args,unsigned int), &flags, buf);
		forward = flags.minus + flags.zero + flags.dot + flags.hashtag +
			flags.space + flags.plus;
	if (flags.conversion != '\0')
		forward++;
	return (forward + 1);
}

void	str_transform(const char *str, va_list args, t_buffer *buf)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (str && str[i])
	{
		if (str[i] == CONVERT_SYMBOL)
		{
			buffer_add_str(buf, str, start, i - start);
			if (str[i + 1])
			{
				i += convert(&str[i], args, buf);
				start = i;
			}
			else
				start = i + 1;
			if (str[i])
				i++;
		}
		else
			i++;
	}
	if (start != i)
		buffer_add_str(buf, str, start, i - start);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_buffer	*buf;
	int			printed_chars;

	buf = buffer_new();
	va_start(args, str);
	str_transform(str, args, buf);
	va_end(args);
	printed_chars = buffer_print_fd(buf, 1);
	buffer_close(&buf);
	return (printed_chars);
}
