/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:56:44 by bzalugas          #+#    #+#             */
/*   Updated: 2021/01/25 21:48:41 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && is_set(s1[i], (char *)set))
		i++;
	if (i < len)
	{
		j = len - 1;
		while (is_set(s1[j], (char *)set))
			j--;
		len = j - i + 1;
	}
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(new, &s1[i], len + 1);
	return (new);
}
