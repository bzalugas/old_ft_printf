/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:04:49 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/31 22:05:31 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

size_t	put_zero(const char *str, t_flags *flags)
{
	size_t	val;
	size_t	forward;

	val = 0;
	if (ft_isdigit(str[1]))
		val = ft_atoi(str + 1);
	if (!flags->dot && !flags->minus)
	{
		flags->zero = 1;
		flags->precision = val;
	}
	else if (flags->dot && !flags->minus)
	{
		flags->min_field = 1;
		flags->padding = val;
	}
	forward = 1;
	while (str[forward] && ft_isdigit(str[forward]))
		forward++;
	return (forward);
}

size_t	put_min_field(const char *str, t_flags *flags)
{
	size_t	val;

	val = ft_atoi(str);
	if (!flags->minus)
	{
		flags->min_field = 1;
		flags->padding = val;
	}
	return (ft_get_pow(val, 1));
}

size_t	put_dot(const char *str, t_flags *flags)
{
	size_t	forward;

	flags->dot = 1;
	if (flags->zero)
	{
		flags->zero = 0;
		flags->min_field = 1;
		flags->padding = flags->precision;
		flags->precision = 0;
	}
	if (str[1] && ft_isdigit(str[1]))
		flags->precision = ft_atoi(str + 1);
	forward = 1;
	while (str[forward] && ft_isdigit(str[forward]))
		forward++;
	return (forward);
}

size_t	put_minus(const char *str, t_flags *flags)
{
	size_t	forward;

	flags->minus = 1;
	if (str[1] && ft_isdigit(str[1]))
		flags->padding = ft_atoi(str + 1);
	forward = 1;
	while (str[forward] && ft_isdigit(str[forward]))
		forward++;
	return (forward);
}

void	flags_init(t_flags *flags)
{
	flags->min_field = 0;
	flags->minus = 0;
	flags->padding = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->conversion = '\0';
}
