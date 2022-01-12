/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfTest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:42 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/12 11:52:44 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "CuTest.h"

void	insufficientArgumentsTest(CuTest *tc)
{
	/* void CuAssert(CuTest* tc, char* message, int condition); */
	/* void CuAssertTrue(CuTest* tc, int condition); */
	/* void CuAssertStrEquals(CuTest* tc, char* expected, char* actual); */
	/* void CuAssertIntEquals(CuTest* tc, int expected, int actual); */
	/* void CuAssertPtrEquals(CuTest* tc, void* expected, void* actual); */
	/* void CuAssertPtrNotNull(CuTest* tc, void* pointer); */
	CuAssert(tc, "test 1 2", ft_printf("bonjour"));
}

CuSuite	*ft_printfGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, insufficientArgumentsTest);
	return (suite);
}
