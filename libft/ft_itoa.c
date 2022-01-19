/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:51:26 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 20:54:04 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	absolute(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	ft_power(unsigned int nb, int pow)
{
	if (nb > 9)
		return (ft_power(nb / 10, pow + 1));
	return (pow);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		pow;
	char	*s;
	size_t	i;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	pow = ft_power(absolute(n), 1);
	s = (char *)ft_calloc(pow + 1 + is_neg, sizeof(char));
	if (!s)
		return (NULL);
	i = pow - 1 + is_neg;
	while (i > 0)
	{
		s[i] = (absolute(n) % 10 + '0');
		n = absolute(n) / 10;
		i--;
	}
	if (is_neg)
		s[i] = '-';
	else
		s[i] = absolute(n) % 10 + '0';
	return (s);
}
