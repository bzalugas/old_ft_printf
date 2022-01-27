/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:51:26 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 17:28:48 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero(void)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		pow;
	char	*s;
	size_t	i;

	if (n == 0)
		return (zero());
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	pow = ft_get_pow(ft_abs(n), 1);
	s = (char *)ft_calloc(pow + 1 + is_neg, sizeof(char));
	if (!s)
		return (NULL);
	i = pow - 1 + is_neg + 1;
	while (--i > 0)
	{
		s[i] = (ft_abs(n) % 10 + '0');
		n = ft_abs(n) / 10;
	}
	if (is_neg)
		s[i] = '-';
	else
		s[i] = ft_abs(n) % 10 + '0';
	return (s);
}
