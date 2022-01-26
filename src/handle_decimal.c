/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:03:30 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/26 16:29:23 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_decimal(int n, t_flags *flags, t_buffer *buf)
{
	int	i;

	i = -1;
	if (flags->space && !flags->dot && !flags->plus)
		buffer_add_char(buf, ' ');
	else if (flags->plus && n > 0)
		buffer_add_char(buf, '+');
	else if (flags->dot)
		while (++i < (flags->precision - ft_get_pow(n, 1)))
			buffer_add_char(buf, '0');
	else if (flags->space)
		buffer_add_char(buf, ' ');
	buffer_add_str(buf, ft_itoa(n), 0, -1);
}
