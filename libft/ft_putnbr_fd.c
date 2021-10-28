/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:47:45 by bzalugas          #+#    #+#             */
/*   Updated: 2021/01/22 15:10:50 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	absolute(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

void				ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (absolute(n) > 9)
		ft_putnbr_fd(absolute(n) / 10, fd);
	ft_putchar_fd(absolute(n) % 10 + '0', fd);
}
