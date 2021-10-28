/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:37:47 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/28 20:10:58 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "src/ft_printf.h"

int	main()
{
	char *str = "Bastien";
	printf("Bonjour %s\n", str);
	ft_printf("Bonjour %s\n", str);
}
