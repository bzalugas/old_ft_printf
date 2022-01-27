/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:49 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 17:23:02 by bzalugas         ###   ########.fr       */
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
	/* RunAllTests(); */
	/* ft_printf("blabla sans flags, %d\n", 23); */
	/* ft_printf("blabla avec flags, %+d\n", 23); */
	/* ft_printf(" %p %p \n", 0,0); */
	/* ft_printf(" %u \n", 0); */
	printf("   printf : %c%c%c*\n",'\0', '1', 1);
	ft_printf("ft_printf : %c%c%c*\n",'\0', '1', 1);
	/* printf("power of 1 : %d et 0 : %d\n", ft_get_pow(1,1), ft_get_pow(0,1)); */
	return (0);
}
