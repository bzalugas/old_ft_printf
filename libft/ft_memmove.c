/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:29:09 by bzalugas          #+#    #+#             */
/*   Updated: 2021/01/16 01:11:31 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst || src)
	{
		if (dst > src)
		{
			i = (int)(len - 1);
			while (i >= 0)
			{
				*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
				i--;
			}
		}
		else
		{
			i = 0;
			while (i < (int)len)
			{
				*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
				i++;
			}
		}
	}
	return (dst);
}
