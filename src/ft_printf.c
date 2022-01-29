/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:29:17 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/29 20:20:00 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	find_conversion(const char *str)
{
	int	i;

	i = -1;
	while (CONVERSION[++i])
		if (CONVERSION[i] == str[0])
			return (CONVERSION[i]);
	return ('\0');
}

int	convert(const char *str, va_list args, t_buffer *buf)
{
	char	conv;

	conv = find_conversion(str + 1);
	if (!conv)
		return (1);
	if (conv == 'c')
		handle_char(va_arg(args, int), buf);
	else if (conv == '%')
		handle_char('%', buf);
	else if (conv == 's')
		handle_string(va_arg(args, char *), buf);
	else if (conv == 'p')
		handle_pointer(va_arg(args, unsigned long), buf);
	else if (conv == 'd' || conv == 'i')
		handle_decimal(va_arg(args, int), buf);
	else if (conv == 'u')
		handle_unsigned(va_arg(args, unsigned int), buf);
	else if (conv == 'x')
		handle_hexa(va_arg(args, unsigned int), 0, buf);
	else if (conv == 'X')
		handle_hexa(va_arg(args, unsigned int), 1, buf);
	return (2);
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
				start = ++i;
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
