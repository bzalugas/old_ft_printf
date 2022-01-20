/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:29:17 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/20 18:18:44 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*find_conversion_directive(const char *str)
{
	int		i;
	int		j;
	char	directive[MAX_FLAGS];

	i = -1;
	while (++i < MAX_FLAGS)
		directive[i] = '\0';
	i = -1;
	j = 0;
	while (FLAGS[++i])
	{
		if (FLAGS[i] == str[j])
		{
			directive[j] = str[j];
			i = 0;
			j++;
		}
	}
	i = -1;
	while (CONVERSION[++i])
	{
		if (CONVERSION[i] == str[j])
			directive[j] = str[j];
	}
	return (ft_substr_free(directive, 0, ft_strlen(directive),0));
}

int	convert(const char *str, va_list args, t_buffer *buf)
{
	int		pos;
	char	*conversion;

	conversion = find_conversion_directive(str + 1);
	if (!*conversion)
		return (0);
	pos = ft_strlen(conversion) - 1;
	if (*conversion && conversion[pos] == 'c')
		buffer_add_char(buf, va_arg(args, int));
	else if (*conversion && conversion[pos] == 's')
		buffer_add_str(buf, va_arg(args, char *), 0, -1);
	/* else if (conversion[pos] == 'p') */
	/* 	/\*Pointer conversion*\/ */
	/* else if (conversion[pos] == 'd') */
	/* 	/\*Decimal conversion*\/ */
	/* else if (conversion[pos] == 'i') */
	/* 	/\*Integer conversion*\/ */
	/* else if (conversion[pos] == 'u') */
	/* 	/\*Unsigned int conversion*\/ */
	/* else if (conversion[pos] == 'x') */
	/* 	/\*lowercase hexa conversion*\/ */
	/* else if (conversion[pos] == 'X') */
	/* 	/\*Uppercase hexa conversion*\/ */
	/* else if (conversion[pos] == '%') */
	/* 	/\*Just put % in buf*\/ */
	return (pos + 1);
}

int	str_transform(const char *str, va_list args, t_buffer *buf)
{
	int	i;
	int	start;
	int	printed_chars;

	i = -1;
	start = 0;
	while (str && str[++i])
	{

		while (str[i] && str[i] != CONVERT_SYMBOL)
			i++;
		buffer_add_str(buf, str, start, i);
		if (str[i] && str[i] == CONVERT_SYMBOL)
			i += convert(&str[i], args, buf);
		printed_chars = i;
	}
	return (printed_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_buffer	*buf;
	int			printed_chars;

	buf = buffer_new();
	va_start(args, str);
	printed_chars = str_transform(str, args, buf);
	va_end(args);
	buffer_print_fd(buf, 1);
	buffer_close(&buf);
	return (printed_chars);
}
