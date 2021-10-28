/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:05:18 by bzalugas          #+#    #+#             */
/*   Updated: 2021/01/16 01:01:38 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	if (dst || src)
	{
		i = -1;
		while (++i < n)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			if (*(unsigned char *)(src + i) == (unsigned char)c)
				return (&dst[i + 1]);
		}
	}
	return (0);
}
