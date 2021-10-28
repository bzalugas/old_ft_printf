/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:05:00 by bzalugas          #+#    #+#             */
/*   Updated: 2021/02/04 17:03:40 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		check;

	count = 0;
	i = 0;
	check = 1;
	while (s && s[i])
	{
		if (check && s[i] != c)
		{
			count++;
			check = 0;
		}
		else if (s[i] == c)
			check = 1;
		i++;
	}
	return (count);
}

static char		*ft_cut(char const *s, char c, size_t *start)
{
	int		rank;
	int		i;
	int		check;
	int		end;
	char	*tmp;

	rank = -1;
	i = *start;
	check = 1;
	end = 0;
	while (s && s[i] && s[i] == c)
		i++;
	*start = i;
	while (s && s[i] && s[i] != c)
		i++;
	if (!(tmp = malloc(sizeof(char) * i - *start + 1)))
		return (NULL);
	ft_strlcpy(tmp, &s[*start], i - *start + 1);
	*start = i;
	return (tmp);
}

static int		ft_cleanup(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**new;
	int		count;
	int		i;
	size_t	start;

	count = ft_count(s, c);
	if (!(new = ft_calloc(count + 1, sizeof(char *))))
		return (NULL);
	i = -1;
	start = 0;
	while (++i < count)
		if (!(new[i] = ft_cut(s, c, &start)) && ft_cleanup(new, i))
			return (NULL);
	return (new);
}
