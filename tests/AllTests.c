/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:49 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/31 21:59:11 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/buffer.h"
#include "CuTest.h"
#include <fcntl.h>

CuSuite *bufferGetSuite();
CuSuite *intermediaryGetSuite();
CuSuite *charTestsGetSuite();
CuSuite *stringTestsGetSuite();
CuSuite *pointerTestsGetSuite();
CuSuite *hexaTestsGetSuite();
CuSuite *decimalTestsGetSuite();
CuSuite	*intTestsGetSuite();
CuSuite	*unsignedTestsGetSuite();
CuSuite	*ft_printfGetSuite();

void	RunAllTests()
{
	CuString	*output = CuStringNew();
	CuSuite		*suite = CuSuiteNew();

	CuSuiteAddSuite(suite, bufferGetSuite());
	CuSuiteAddSuite(suite, intermediaryGetSuite());
	CuSuiteAddSuite(suite, charTestsGetSuite());
	CuSuiteAddSuite(suite, stringTestsGetSuite());
	CuSuiteAddSuite(suite, pointerTestsGetSuite());
	CuSuiteAddSuite(suite, hexaTestsGetSuite());
	CuSuiteAddSuite(suite, decimalTestsGetSuite());
	CuSuiteAddSuite(suite, intTestsGetSuite());
	CuSuiteAddSuite(suite, unsignedTestsGetSuite());
	CuSuiteAddSuite(suite, ft_printfGetSuite());

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
