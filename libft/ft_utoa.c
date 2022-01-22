/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:21:04 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/22 10:43:58 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(unsigned long nb, int pow)
{
	if (nb > 9)
		return (ft_power(nb / 10, pow + 1));
	return (pow);
}

char	*ft_utoa(unsigned long n)
{
	unsigned long	pow;
	char			*s;
	size_t			i;
	
	pow = ft_power(n, 1);
	s = malloc(sizeof(char) * pow + 1);
	if (!s)
		return (NULL);
	s[pow] = '\0';
	i = pow - 1;
	while (i >= 0 && n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
