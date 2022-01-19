/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 23:01:08 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 20:45:46 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*cel;
	void	*tmp;

	first = NULL;
	if (f)
	{
		while (lst)
		{
			tmp = f(lst->content);
			cel = ft_lstnew(tmp);
			if (!tmp || !cel)
			{
				if (del)
					ft_lstclear(&first, del);
				return (NULL);
			}
			ft_lstadd_back(&first, cel);
			lst = lst->next;
		}
	}
	return (first);
}
