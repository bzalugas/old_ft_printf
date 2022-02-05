/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:45:56 by bzalugas          #+#    #+#             */
/*   Updated: 2022/02/05 09:58:16 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_flag(const char *str, t_flags *flags)
{
	size_t	forward;

	forward = 0;
	if (ft_isdigit(str[0]) && str[0] != '0')
		forward = put_min_field(str, flags);
	else if (str[0] == '-')
		forward = put_minus(str, flags);
	else if (str[0] == '0')
		forward = put_zero(str, flags);
	else if (str[0] == '.')
		forward = put_dot(str, flags);
	else
	{
		if (str[0] == '#')
			flags->sharp = 1;
		if (str[0] == ' ')
			flags->space = 1;
		if (str[0] == '+')
			flags->plus = 1;
		else
			flags->conversion = str[0];
		forward++;
	}
	return (forward);
}

t_flags	find_flags(const char *str, size_t *forward)
{
	int		i;
	t_flags	flags;

	flags_init(&flags);
	i = -1;
	*forward = 0;
	while (FLAGS[++i])
	{
		if (str[*forward] == FLAGS[i] || ft_isdigit(str[*forward]))
		{
			*forward += put_flag(&str[*forward], &flags);
			i = -1;
		}
	}
	i = 0;
	while (CONVERSION[i] && CONVERSION[i] != str[*forward])
		i++;
	if (CONVERSION[i] && CONVERSION[i] == str[*forward])
		*forward += put_flag(&CONVERSION[i], &flags);
	return (flags);
}

int	convert(const char *str, va_list args, t_buffer *buf)
{
	t_flags	flags;
	size_t	forward;

	flags = find_flags(str + 1, &forward);
	if (flags.conversion == 'c')
		handle_char(va_arg(args, int), &flags, buf);
	else if (flags.conversion == '%')
		handle_char('%', &flags, buf);
	else if (flags.conversion == 's')
		handle_string(va_arg(args, char *), &flags, buf);
	else if (flags.conversion == 'p')
		handle_pointer(va_arg(args, unsigned long), &flags, buf);
	else if (flags.conversion == 'd' || flags.conversion == 'i')
		handle_decimal(va_arg(args, int), &flags, buf);
	else if (flags.conversion == 'u')
		handle_unsigned(va_arg(args, unsigned int), &flags, buf);
	else if (flags.conversion == 'x' || flags.conversion == 'X')
		handle_hexa(va_arg(args, unsigned int), &flags, buf);
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
