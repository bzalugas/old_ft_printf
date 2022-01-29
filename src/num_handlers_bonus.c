/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handlers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:05:28 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/29 16:42:41 by bzalugas         ###   ########.fr       */
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
	if (flags->min_field && !flags->minus && flags->min_padding > len)
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

	num = ft_itoa(n);
	len = ft_strlen(num);
	if (flags->min_field && !flags->minus && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	buffer_add_str(buf, num, 0, len);
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
	if (flags->min_field && !flags->minus && flags->min_padding > len)
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
	if (flags->min_field && !flags->minus && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	buffer_add_str(buf, hexa, 0, -1);
	if (flags->minus && flags->min_padding > len)
		add_spaces_buf(flags->min_padding - len, buf);
	free(hexa);
}
