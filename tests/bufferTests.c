/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferTests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:46:15 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 11:45:32 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../includes/ft_printf.h" */
#include "../includes/buffer.h"
#include "CuTest.h"

#define MAX_BUF 10000

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
	/* for (int i = 'A'; i <= 'Z'; i++) */
	/* 	buffer_add_char(buf, i); */
	buffer_add_str(buf, "ABCDEFGHIJKLMNOPQRSTUVWXYZ",0,-1);
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
	close(pipefds[0]);

	buffer_close(&buf);
	CuAssertStrEquals(tc, expected_print, actual_print);
}

void	bigStringTest(CuTest *tc)
{
	t_buffer	*buf;
	char		*input;
	char		*actual_print;
	int			stdout_bk;
	int			pipefds[2];
	char		buff[MAX_BUF];
	int			res;

	input = "ABCDEFGHIJKLMNOPQRSTUVWXYZsfljdkfas;dlkfjsdlfkjsdl;kjfl;sakjdflksadjfl;kjsadlfkjsdlkjflskdfljsdlfkjsadlfkjdslfkjsdlkfjlsdkjflsdjflkjsdalfjsdlfjsldkjflsdljfsdlfjkldsakjflsdkjfljksdjfljsdljfldsjlfjsadkjfljsdljflksdfjldsjlfkjlsdjflkjsdlfkjdslkfjlsdkjflkjslkjflesjkfsjfkjsdkfjsdkfjsdkjflkjdsklfksdlfjlsadkjflakejsjfkesjfjigjhsdkgjhdkjhghdfgjhdsfkjhdskfjhsdkljhfhsdjhfkljhsadfhasdflkjhlkdsfjhlkuhasefiuhaesifuh iefuhfkhsadhf khasfdkljhfkjshdfklfjdsh kfdhs kjdhf kljsdfhkfdjh kdfhklsfdjh lksdjhflkj hdsfkjhdsfkljfh lkdjfhs kjdfh lkjdfhlksdfjhlkdfsjhdsfkl jfkljashdfkldjfsh kljhdsfkjfdhs lkfjhkdjsfhkdsljfhkldjshfklsdjhflksdjhsfkjhsdfkjdhsfkdjsfhkjdfhfskdjhdsfkhfdkjdfshkjdsh fkjhfksjdhfk sdjhdfkjhkfdsjh kfsdj hfdskjhfksjdhf kjsfdhkfdsjh fksdjhfkjsdhkdsjhjsdfhfdksjhdsfkjhfdskjhdfsksjhflkdsjgfhhjbfdjkfhkjhdsffjksdfhdfkjhsfdkjhfdskjsdfhlsdfkjhskdfjhfkjhsdfkjhfsdkjfskdfsjhsdkjhfdskjhfksdhdsjkhfsjsdkfdskjfhsdkjfsdkjhfkjsdhfkjdshfkjsdhfksjhdfkjhsdfkjhsdflkjhdfskljhflksdufhskldfjhklsdjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjxccccccccccccccccccccccccccccccccccccccccccccccccccccccckzxhvklhcxzklhvxklcjhvkhxckldv zkhmxvklhjxzckhjcx kh xhchxzklhcvkbxckvcxhbvkl lxcvkjhxckl hvklxcjhvlkx cjvhlkjxchvkxcvhlkhvlxcvhllkxvjchkxcvhkxcjhvbj kzxkcvhxkj hvkxzjc xbcvkjbxcvjklcbx kjb xcjkcvb klxjbzclvdskfdjfljds;ljfl;sd;fkfjds;lsdjf";
	buf = buffer_new();
	buffer_add_str(buf, input, 0, -1);

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
	close(pipefds[0]);

	buffer_close(&buf);
	CuAssertStrEquals(tc, input, actual_print);
}

void	emptyTest(CuTest *tc)
{
	t_buffer	*buf;
	char		*expected_print;
	char		*actual_print;
	int			stdout_bk;
	int			pipefds[2];
	char		buff[MAX_BUF];
	int			res;

	buf = buffer_new();
	expected_print = "";
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
	close(pipefds[0]);

	buffer_close(&buf);
	CuAssertStrEquals(tc, expected_print, actual_print);
}

void	substrTest(CuTest *tc)
{
	t_buffer	*buf;
	char		*expected_print;
	char		*actual_print;
	int			stdout_bk;
	int			pipefds[2];
	char		buff[MAX_BUF];
	int			res;

	buf = buffer_new();
	/* for (int i = 'A'; i <= 'Z'; i++) */
	/* 	buffer_add_char(buf, i); */
	buffer_add_str(buf, "ABCDEFGHIJKLMNOPQRSTUVWXYZ",0,10);
	expected_print = "ABCDEFGHIJ";
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
	close(pipefds[0]);

	buffer_close(&buf);
	CuAssertStrEquals(tc, expected_print, actual_print);
}

void	multipleBufStringsTest(CuTest *tc)
{
	t_buffer	*buf;
	char		*expected_print;
	char		*actual_print;
	int			stdout_bk;
	int			pipefds[2];
	char		buff[MAX_BUF];
	int			res;

	buf = buffer_new();
	buffer_add_str(buf, "premiere string ",0,-1);
	buffer_add_str(buf, "suivie par la seconde string", 0, -1);
	expected_print = "premiere string suivie par la seconde string";

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
	close(pipefds[0]);

	buffer_close(&buf);
	CuAssertStrEquals(tc, expected_print, actual_print);
}

CuSuite	*bufferGetSuite()
{
	CuSuite	*suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, basicTest);
	SUITE_ADD_TEST(suite, emptyTest);
	SUITE_ADD_TEST(suite, bigStringTest);
	SUITE_ADD_TEST(suite, substrTest);
	SUITE_ADD_TEST(suite, multipleBufStringsTest);
	return (suite);
}
