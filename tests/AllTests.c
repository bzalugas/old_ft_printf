/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:49 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 16:37:59 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/buffer.h"
#include "CuTest.h"
#include <fcntl.h>

CuSuite	*ft_printfGetSuite();
CuSuite *bufferGetSuite();

void	RunAllTests()
{
	CuString	*output = CuStringNew();
	CuSuite		*suite = CuSuiteNew();

	CuSuiteAddSuite(suite, ft_printfGetSuite());
	CuSuiteAddSuite(suite, bufferGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
	CuStringDelete(output);
	CuSuiteDelete(suite);
}

int		main(void)
{
	RunAllTests();
	return (0);
}
