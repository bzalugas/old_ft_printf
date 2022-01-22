/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:11:03 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/22 17:31:06 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

char	*pointer_to_hexa(void *p, int upper_case)
{
	char	*pointer;
	char	*hexa;

	pointer = ft_utoa((unsigned long)p);
	if (upper_case)
		hexa = 	ft_base_convert(pointer, "0123456789", "0123456789ABCDEF");
	else
		hexa = ft_base_convert(pointer, "0123456789", "0123456789abcdef");
	return (hexa);
}
