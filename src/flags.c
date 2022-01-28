/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:04:49 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/28 11:46:30 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

size_t	put_min_field(const char *str, t_flags *flags)
{
	flags->min_field = 1;
	flags->min_padding = ft_atoi(str);
	return (ft_get_pow(flags->min_padding, 1));
}

size_t	put_dot(const char *str, t_flags *flags)
{
	flags->dot = 1;
	if (str[1] && ft_isdigit(str[1]))
		flags->precision = ft_atoi(str + 1);
	return (ft_get_pow(flags->precision, 1));
}

size_t	put_minus(const char *str, t_flags *flags)
{
	flags->minus = 1;
	if (str[1] && ft_isdigit(str[1]))
		flags->min_padding = ft_atoi(str + 1);
	else
		return (0);
	return (ft_get_pow(flags->min_padding, 1));
}

void	flags_init(t_flags *flags)
{
	flags->min_field = 0;
	flags->minus = 0;
	flags->min_padding = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->conversion = '\0';
}
