/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfTest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:30:42 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 12:55:14 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "CuTest.h"

#define MAX_BUF 1000001

void	basicPrintfTests(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;
	void	*pointer;

	printf("basic printf tests\n");
	pointer = malloc(sizeof(void *));
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("test simple.\nMon char : %c puis %s, %d%d ainsi que %i%i et %u maintenant %p et enfin %x %X %%\n",
		'B', "Je suis une string haha", 23,23,23,23,23, pointer, 23,23);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("test simple.\nMon char : %c puis %s, %d%d ainsi que %i%i et %u maintenant %p et enfin %x %X %%\n",
		'B', "Je suis une string haha", 23,23,23,23,23, pointer, 23,23);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	actual_print = ft_strdup(buf);
	close(pipefds[0]);
	free(pointer);

	CuAssertStrEquals(tc, expected_print, actual_print);
	CuAssertIntEquals(tc, expected_return, actual_return);
}

void	emptyStringTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("emptyStringTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("");
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

void	multipleStringsTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("multipleStringsTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("bonjour, ""je suis dans une autre string\n");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("bonjour, ""je suis dans une autre string\n");
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

/* void	percentBeforeEndTest(CuTest *tc) */
/* { */
/* 	int		expected_return; */
/* 	int		actual_return; */
/* 	char	*expected_print; */
/* 	char	*actual_print; */
/* 	int		stdout_bk; */
/* 	int		pipefds[2]; */
/* 	char	buf[MAX_BUF]; */
/* 	int		res; */

/* 	printf("percentBeforeEndTest\n"); */
/* 	stdout_bk = dup(fileno(stdout)); */
/* 	pipe(pipefds); */
/* 	dup2(pipefds[1], fileno(stdout)); */
/* 	expected_return = printf("Voici un texte a afficher : %"); */
/* 	fflush(stdout); */
/* 	close(pipefds[1]); */
/* 	dup2(stdout_bk, fileno(stdout)); */
/* 	res = read(pipefds[0], buf, MAX_BUF); */
/* 	buf[res] = '\0'; */
/* 	expected_print = ft_strdup(buf); */
/* close(pipefds[0]); */

/* 	pipe(pipefds); */
/* 	dup2(pipefds[1], fileno(stdout)); */
/* 	actual_return = ft_printf("Voici un texte a afficher : %"); */
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

void	alonePercentTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("alonePercentTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Une string avec des %% tous seuls % % ");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Une string avec des %% tous seuls % % ");
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

CuSuite	*ft_printfGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	/* SUITE_ADD_TEST(suite, insufficientArgumentsTest); */
	SUITE_ADD_TEST(suite, emptyStringTest);
	SUITE_ADD_TEST(suite, multipleStringsTest);
	/* SUITE_ADD_TEST(suite, percentBeforeEndTest); */
	/* SUITE_ADD_TEST(suite, alonePercentTest); */
	return (suite);
}
