#include <stdio.h>
#define STR "bonjour tout le monde"

int main(void)
{
	int i = -1;
	while (STR[++i])
		printf("%c", STR[i]);
	return (0);
}
