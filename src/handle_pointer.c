/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:37:16 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/22 18:54:47 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	handle_pointer(unsigned long p, t_buffer *buf)
{
	char	*hexa;

	hexa = NULL;
	hexa = pointer_to_hexa(p, 0);
	if (hexa)
		buffer_add_str(buf, "0x", 0, 2);
	buffer_add_str(buf, hexa, 0, -1);
}
