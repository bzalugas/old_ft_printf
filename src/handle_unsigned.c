/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:02:25 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/26 20:27:41 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_unsigned(unsigned n, t_flags *flags, t_buffer *buf)
{
	int	i;
	int	len;

	i = -1;
	len = ft_get_pow(n, 1);
	if (flags->space)
		buffer_add_char(buf, ' ');
	if (flags->dot)
		while (++i < flags->precision - len)
			buffer_add_char(buf, '0');
	buffer_add_str(buf, ft_utoa(n), 0, -1);
}
