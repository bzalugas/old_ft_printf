/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:06:11 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 13:02:02 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	handle_char(int c, t_buffer *buf)
{
	char	character = c;

	buffer_add_char(buf, character);
}

void	handle_string(const char *str, t_flags *flags, t_buffer *buf)
{
	int	length;

	length = -1;
	if (flags->dot)
		length = flags->precision;
	if (!str)
		str = "(null)";
	buffer_add_str(buf, str, 0, length);
}
