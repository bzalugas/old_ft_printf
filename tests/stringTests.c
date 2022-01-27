/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringTests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:06:04 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 11:48:25 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CuTest.h"
#include "../includes/ft_printf.h"

#define MAX_BUF 100001

void	basicStringTests(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("basicStringTests\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici ma string a afficher : %s\n", "Salut tout le monde !");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici ma string a afficher : %s\n", "Salut tout le monde !");
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

void	multipleSTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("multipleSTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici mes strings a afficher : %s, %s, %s\n", "Salut tout le monde !",
		"Je suis Bastien", "Il fait pas beau");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici mes strings a afficher : %s, %s, %s\n", "Salut tout le monde !",
		"Je suis Bastien", "Il fait pas beau");
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

void	nullStringArgumentTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("nullStringArgumentTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici ma string a afficher : %s\n", (char *)NULL);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici ma string a afficher : %s\n", (char *)NULL);
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

void	emptyStringArgumentTest(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("emptyStringArgumentTest\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici ma string a afficher : %s\n","");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici ma string a afficher : %s\n","");
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

void	stringFlagsTests(CuTest *tc)
{
	int		expected_return;
	int		actual_return;
	char	*expected_print;
	char	*actual_print;
	int		stdout_bk;
	int		pipefds[2];
	char	buf[MAX_BUF];
	int		res;

	printf("stringFlagsTests\n");
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	expected_return = printf("Voici ma string a afficher : %.5s\n","Bastien");
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buf, MAX_BUF);
	buf[res] = '\0';
	expected_print = ft_strdup(buf);
	close(pipefds[0]);

	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	actual_return = ft_printf("Voici ma string a afficher : %.5s\n","Bastien");
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

CuSuite	*stringTestsGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, basicStringTests);
	SUITE_ADD_TEST(suite, multipleSTest);
	SUITE_ADD_TEST(suite, nullStringArgumentTest);
	SUITE_ADD_TEST(suite, emptyStringArgumentTest);
	return (suite);
}
