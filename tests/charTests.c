/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charTests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:03:15 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/26 16:05:50 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CuTest.h"
#include "../includes/ft_printf.h"

#define MAX_BUF 100001

void	basicCharTests(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("basicCharTests\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici mon char a afficher : %c", 'B');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici mon char a afficher : %c", 'B');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici mon char a afficher : %c", '%');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici mon char a afficher : %c", '%');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici mon char a afficher : %%");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici mon char a afficher : %%");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

void	multipleCharsTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("multipleCharsTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici mes chars a afficher : %c%c%c%%%c%c%c%c", 'B','o','n','j','o','u','r');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici mes chars a afficher : %c%c%c%%%c%c%c%c", 'B','o','n','j','o','u','r');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

CuSuite	*charTestsGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, basicCharTests);
	SUITE_ADD_TEST(suite, multipleCharsTest);
	return (suite);
}
