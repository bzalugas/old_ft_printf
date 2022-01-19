/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:16:54 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 21:06:24 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_free(char *s, unsigned int start, size_t len, int free_s)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			new[i] = s[start + i];
			i++;
		}
	}
	new[i] = '\0';
	if (free_s && s)
		free(s);
	return (new);
}
