/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:46:36 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/21 13:00:16 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_string(const char *str, t_flags flags, t_buffer *buf)
{
	int	length;

	length = -1;
	if (flags.dot)
		length = flags.precision;
	buffer_add_str(buf, str, 0, length);
}
