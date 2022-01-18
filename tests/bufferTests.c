/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferTests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:46:15 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/18 19:37:20 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../includes/ft_printf.h" */
#include "../includes/buffer.h"
#include "CuTest.h"

#define MAX_BUF 101

void	basicTest(CuTest *tc)
{
	t_buffer	*buf;
	char		*expected_print;
	char		*actual_print;
	int			stdout_bk;
	int			pipefds[2];
	char		buff[MAX_BUF];
	int			res;

	buf = buffer_new();
	for (int i = 'A'; i <= 'Z'; i++)
		buffer_add_char(buf, i);
	expected_print = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	/*Pipe communication*/
	stdout_bk = dup(fileno(stdout));
	pipe(pipefds);
	dup2(pipefds[1], fileno(stdout));
	buffer_print_fd(buf,1);
	fflush(stdout);
	close(pipefds[1]);
	dup2(stdout_bk, fileno(stdout));
	res = read(pipefds[0], buff, MAX_BUF);
	buff[res] = '\0';
	actual_print = ft_strdup(buff);

	buffer_close(&buf);
	CuAssertStrEquals(tc, expected_print, actual_print);
}

CuSuite	*bufferGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, basicTest);
	return (suite);
}
