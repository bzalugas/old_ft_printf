/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediaryTests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:49:03 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/22 16:30:17 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
#include "CuTest.h"

#define MAX_BUF 101

void	pointer_to_hexaTests(CuTest *tc)
{
	void		*pointer;
	char		*expected;
	char		*actual;
	int			stdout_bk;
	int			pipefds[2];
	char		buff[MAX_BUF];
	int			res;


	printf("pointer_to_hexaTests\n");
	/*Pipe communication*/
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	printf("%p", pointer);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buff, MAX_BUF);
	buff[res] = '\0';
	expected = ft_strdup(buff);
	actual = pointer_to_hexa(pointer, 0);

	CuAssertStrEquals(tc, expected, actual);
}

CuSuite	*intermediaryGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, pointer_to_hexaTests);
	return (suite);
}
