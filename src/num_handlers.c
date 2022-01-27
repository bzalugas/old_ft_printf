/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:05:28 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 12:20:10 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pointer_to_hexa(unsigned long p, int upper_case)
{
	char	*pointer;
	char	*hexa;

	pointer = ft_utoa(p);
	if (!*pointer)
		pointer = "0";
	hexa = NULL;
	if (upper_case)
		hexa = 	ft_base_convert(pointer, "0123456789", "0123456789ABCDEF");
	else
		hexa = ft_base_convert(pointer, "0123456789", "0123456789abcdef");
	return (hexa);
}

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

void	handle_decimal(int n, t_flags *flags, t_buffer *buf)
{
	int	i;
	int	len;

	i = -1;
	len = ft_get_pow(n, 1);
	if (flags->space && !flags->dot && !flags->plus)
		buffer_add_char(buf, ' ');
	else if (flags->plus && n > 0)
		buffer_add_char(buf, '+');
	else if (flags->dot)
		while (++i < (flags->precision - len))
			buffer_add_char(buf, '0');
	/* else if (flags->space) */
	/* 	buffer_add_char(buf, ' '); */
	buffer_add_str(buf, ft_itoa(n), 0, -1);
}

void	handle_hexa(unsigned int n, t_flags *flags, t_buffer *buf)
{
	int		upper_case;
	int		alt_form;
	char	*hexa;
	char	*pre;

	upper_case = 0;
	alt_form = 0;
	pre = "0x";
	if (flags->conversion == 'X')
	{
		upper_case = 1;
		pre = "0X";
	}
	if (flags->hashtag)
		alt_form = 1;
	hexa = NULL;
	hexa = pointer_to_hexa(n, upper_case);
	if (hexa && flags->hashtag)
		buffer_add_str(buf, pre, 0, 2);
	buffer_add_str(buf, hexa, 0, -1);
}

void	handle_pointer(unsigned long p, t_buffer *buf)
{
	char	*hexa;

	hexa = NULL;
	hexa = pointer_to_hexa(p, 0);
	if (hexa)
		buffer_add_str(buf, "0x", 0, 2);
	buffer_add_str(buf, hexa, 0, -1);
}
