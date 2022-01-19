/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:30:07 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 21:04:27 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2)
{
	size_t	len1;
	size_t	len2;
	int		i;
	char	*new;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(sizeof(char) * len1 + len2 + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		new[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		new[len1 + i] = s2[i];
	if (i < 0)
		i = 0;
	new[len1 + i] = '\0';
	if (free_s1 && s1)
		free(s1);
	if (free_s2 && s2)
		free(s2);
	return (new);
}
