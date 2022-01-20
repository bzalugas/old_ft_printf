/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:54:10 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 20:52:04 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base(char *base)
{
	int	i;

	i = -1;
	if (!base)
		return (0);
	while (base[++i])
		if (!ft_isalnum(base[i]))
			return (0);
	return (1);
}

static int	is_numbase(char **num, char *base)
{
	int	i;
	int	start;

	if (!*num || !base)
		return (0);
	start = 0;
	while (*(*num + start) && !ft_isalnum(*(*num + start)))
		start++;
	i = start;
	while (*(*num + i))
		if (ft_find_char(*(*num + i++), base) == -1)
			return (0);
	*num = *num + start;
	return (1);
}

static char	*lst_to_str(t_list *lst)
{
	t_list	*tmp;
	char	*str;
	char	*content;
	int		i;
	void	(*del)(void *);

	str = malloc(sizeof(char) * ft_lstsize(lst) + 1);
	if (!str)
		return (NULL);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		content = tmp->content;
		str[i++] = *content;
		tmp = tmp->next;
	}
	del = &ft_lstdelcontent;
	ft_lstclear(&lst, del);
	return (str);
}

static char	*ite_dec_to_base(int nb, char *base, int len)
{
	t_list	*lst;
	char	c;

	while (nb > 0)
	{
		c = base[nb % len];
		ft_lstadd_front(&lst, ft_lstnew(ft_strdup(&c)));
		nb /= len;
	}
	return (lst_to_str(lst));
}

char	*ft_base_convert(char *num, char *src_base, char *dst_base)
{
	int	nb;
	int	i;
	int	src_len;
	int	dst_len;

	if (is_base(src_base) && is_numbase(&num, src_base))
	{
		src_len = ft_strlen(src_base);
		dst_len = ft_strlen(dst_base);
		nb = 0;
		i = -1;
		while (num && num[++i])
			nb = nb * src_len + ft_find_char(num[i], src_base);
		if (is_base(dst_base))
			return (ite_dec_to_base(nb, dst_base, dst_len));
		return (ite_dec_to_base(nb, "0123456789", 10));
	}
	return (NULL);
}
