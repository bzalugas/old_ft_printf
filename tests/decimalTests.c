/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimalTests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:09:11 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 11:50:37 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CuTest.h"
#include "../includes/ft_printf.h"

#define MAX_BUF 100001

void	basicDecimalTests(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("basicDecimalTests\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

void	decimalFlagsTests(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("decimalFlagsTests\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %0d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %0d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %.9d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %.9d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %-3d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %-3d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : % d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : % d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %+d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %+d", 234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %+d", -234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %+d", -234567);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);

	/* stdout_bk = dup(fileno(stdout)); */
	/* pipe(pipefds); */
	/* dup2(pipefds[1], fileno(stdout)); */
	/* expected_return = printf("Mon decimal : %+ d", 234567); */
	/* fflush(stdout); */
	/* close(pipefds[1]); */
	/* dup2(stdout_bk, fileno(stdout)); */
	/* res = read(pipefds[0], buf, MAX_BUF); */
	/* buf[res] = '\0'; */
	/* expected_print = ft_strdup(buf); */
	/* close(pipefds[0]); */

	/* pipe(pipefds); */
	/* dup2(pipefds[1], fileno(stdout)); */
	/* actual_return = ft_printf("Mon decimal : %+ d", 234567); */
	/* fflush(stdout); */
	/* close(pipefds[1]); */
	/* dup2(stdout_bk, fileno(stdout)); */
	/* res = read(pipefds[0], buf, MAX_BUF); */
	/* buf[res] = '\0'; */
	/* actual_print = ft_strdup(buf); */
	/* close(pipefds[0]); */

	/* CuAssertStrEquals(tc, expected_print, actual_print); */
	/* CuAssertIntEquals(tc, expected_return, actual_return); */
}

/* void	outOfRangeIntTests(CuTest *tc) */
/* { */
/* 	int		expected_return; */
/* 	int		actual_return; */
/* 	char	*expected_print; */
/* 	char	*actual_print; */
/* 	int		stdout_bk; */
/* 	int		pipefds[2]; */
/* 	char	buf[MAX_BUF]; */
/* 	int		res; */

/* 	printf("outOfRangeIntTests\n"); */
/* 	stdout_bk = dup(fileno(stdout)); */
/* 	pipe(pipefds); */
/* 	dup2(pipefds[1], fileno(stdout)); */
/* 	expected_return = printf("Mon decimal : %d", 2147483648); */
/* 	fflush(stdout); */
/* 	close(pipefds[1]); */
/* 	dup2(stdout_bk, fileno(stdout)); */
/* 	res = read(pipefds[0], buf, MAX_BUF); */
/* 	buf[res] = '\0'; */
/* 	expected_print = ft_strdup(buf); */
/* close(pipefds[0]); */

/* 	pipe(pipefds); */
/* 	dup2(pipefds[1], fileno(stdout)); */
/* 	actual_return = ft_printf("Mon decimal : %d", 2147483648); */
/* 	fflush(stdout); */
/* 	close(pipefds[1]); */
/* 	dup2(stdout_bk, fileno(stdout)); */
/* 	res = read(pipefds[0], buf, MAX_BUF); */
/* 	buf[res] = '\0'; */
/* 	actual_print = ft_strdup(buf); */
/* close(pipefds[0]); */

/* 	CuAssertStrEquals(tc, expected_print, actual_print); */
/* 	CuAssertIntEquals(tc, expected_return, actual_return); */

/* 	stdout_bk = dup(fileno(stdout)); */
/* 	pipe(pipefds); */
/* 	dup2(pipefds[1], fileno(stdout)); */
/* 	expected_return = printf("Mon decimal : %d", -2147483649); */
/* 	fflush(stdout); */
/* 	close(pipefds[1]); */
/* 	dup2(stdout_bk, fileno(stdout)); */
/* 	res = read(pipefds[0], buf, MAX_BUF); */
/* 	buf[res] = '\0'; */
/* 	expected_print = ft_strdup(buf); */
/* close(pipefds[0]); */

/* 	pipe(pipefds); */
/* 	dup2(pipefds[1], fileno(stdout)); */
/* 	actual_return = ft_printf("Mon decimal : %d", -2147483649); */
/* 	fflush(stdout); */
/* 	close(pipefds[1]); */
/* 	dup2(stdout_bk, fileno(stdout)); */
/* 	res = read(pipefds[0], buf, MAX_BUF); */
/* 	buf[res] = '\0'; */
/* 	actual_print = ft_strdup(buf); */
/* close(pipefds[0]); */

/* 	CuAssertStrEquals(tc, expected_print, actual_print); */
/* 	CuAssertIntEquals(tc, expected_return, actual_return); */
/* } */

void	charArgumentForPercentDTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("charArgumentPercentD\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon decimal : %d", 'z');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon decimal : %d", 'z');
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

void	hexaArgumentPercentDTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("hexaArgumentPercentI\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Mon integer : %i", 0x2345681);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Mon integer : %i", 0x2345681);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

CuSuite	*decimalTestsGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, basicDecimalTests);
	SUITE_ADD_TEST(suite, decimalFlagsTests);
	/* SUITE_ADD_TEST(suite, outOfRangeIntTests); */
	SUITE_ADD_TEST(suite, charArgumentForPercentDTest);
	SUITE_ADD_TEST(suite, hexaArgumentPercentDTest);
	return (suite);
}
