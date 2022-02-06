/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:21:04 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 17:30:14 by bzalugas         ###   ########.fr       */
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

char	*ft_utoa(unsigned long n)
{
	int	pow;
	char			*s;
	size_t			i;

	if (n == 0)
		return (zero());
	pow = ft_get_pow(n, 1);
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
