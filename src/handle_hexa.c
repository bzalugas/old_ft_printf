/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:19:38 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/22 18:44:11 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

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
		buffer_add_str(buf, pre, 0, 3);
	buffer_add_str(buf, hexa, 0, -1);
}
