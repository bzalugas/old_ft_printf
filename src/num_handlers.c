/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:05:28 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/29 20:21:50 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	handle_unsigned(unsigned n, t_buffer *buf)
{
	char	*num;

	num = ft_utoa(n);
	buffer_add_str(buf, num, 0, -1);
	free(num);
}

void	handle_decimal(int n, t_buffer *buf)
{
	char	*num;

	num = ft_itoa(n);
	buffer_add_str(buf, num, 0, -1);
	free(num);
}

void	handle_hexa(unsigned int n, int upper_case, t_buffer *buf)
{
	char	*hexa;

	hexa = pointer_to_hexa(n, upper_case);
	buffer_add_str(buf, hexa, 0, -1);
	free(hexa);
}

void	handle_pointer(unsigned long p, t_buffer *buf)
{
	char	*hexa;

	hexa = pointer_to_hexa(p, 0);
	if (hexa)
		buffer_add_str(buf, "0x", 0, 2);
	buffer_add_str(buf, hexa, 0, -1);
	free(hexa);
}
