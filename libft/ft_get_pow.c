/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:16:15 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/29 20:13:12 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_pow(unsigned long nb, int pow)
{
	if (nb == 0 && pow == 1)
		return (0);
	if (nb < 10)
		return (pow);
	return (ft_get_pow(nb / 10, pow + 1));
}
