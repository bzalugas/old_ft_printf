/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:04:18 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/29 20:19:01 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	add_spaces_buf(size_t len, t_buffer *buf)
{
	unsigned int	i;

	i = 0;
	while (++i < len + 1)
		buffer_add_char(buf, ' ');
}

void	add_zeros_buf(size_t len, t_buffer *buf)
{
	unsigned int	i;

	i = 0;
	while (++i < len + 1)
		buffer_add_char(buf, '0');
}
