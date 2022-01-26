/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerTests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:07:43 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/26 16:08:49 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CuTest.h"
#include "../includes/ft_printf.h"

#define MAX_BUF 100001

void	basicPointerTests(CuTest *tc)
{
	void	*pointer;
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("basicPointerTests\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("affiche mon pointeur : %p\n",pointer);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("affiche mon pointeur : %p\n",pointer);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

void	nullPointerTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("NullPointerTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("affiche mon pointeur null : %p\n",NULL);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("affiche mon pointeur null : %p\n",NULL);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

CuSuite	*pointerTestsGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, basicPointerTests);
	SUITE_ADD_TEST(suite, nullPointerTest);
	return (suite);
}
