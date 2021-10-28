/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:29:17 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/29 00:27:44 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;

	va_start(list, str);
	i = -1;
	while (str[++i] && str[i] != '%')
		ft_putchar_fd(str[i],1);
	if (str[i] == '%')
		i++;
	if (str[i] && str[i] == 's')
		ft_putstr_fd(va_arg(list, char *), 1);
	while (str[++i])
		ft_putchar_fd(str[i], 1);
	return (0);
}
