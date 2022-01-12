/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfTest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:42 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/12 14:59:50 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "CuTest.h"

#define MAX_BUF 101

void	insufficientArgumentsTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon char : %c");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon char : %c");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	/* void CuAssert(CuTest* tc, char* message, int condition); */
	/* void CuAssertTrue(CuTest* tc, int condition); */
	/* void CuAssertStrEquals(CuTest* tc, char* expected, char* actual); */
	/* void CuAssertIntEquals(CuTest* tc, int expected, int actual); */
	/* void CuAssertPtrEquals(CuTest* tc, void* expected, void* actual); */
	/* void CuAssertPtrNotNull(CuTest* tc, void* pointer); */
}

CuSuite	*ft_printfGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, insufficientArgumentsTest);
	return (suite);
}
