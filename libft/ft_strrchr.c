/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 03:05:25 by bzalugas          #+#    #+#             */
/*   Updated: 2021/01/16 04:35:25 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while (s[++i])
		if (s[i] == (char)c)
			tmp = (char *)&s[i];
	if (!s[i] && c == '\0')
		return ((char *)&s[i]);
	return (tmp);
}
