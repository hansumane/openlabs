/*
 * По введенному с клавиатуры n найти n!
 * * *
 * Способ с рекурсивной функцией
 */

#include <stdio.h>

unsigned
factorial(unsigned n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int
main(void)
{
	unsigned n;
	fputs("input n: ", stdout);
	scanf("%u", &n);
	getchar();

	printf("result: n! = %u\n", factorial(n));

	return 0;
}
