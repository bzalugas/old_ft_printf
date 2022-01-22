/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:04:49 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/22 19:06:23 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	flags_init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->conversion = '\0';
}
