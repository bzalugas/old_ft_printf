/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:16:54 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 20:50:00 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_strlcpy(new, "\0", 1);
	else
		ft_strlcpy(new, &s[start], len + 1);
	return (new);
}
