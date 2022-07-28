/*
 * По введенному с клавиатуры n найти n!
 * * *
 * Способ без функций
 */

#include <stdio.h>

int
main(void)
{
	unsigned res = 1, n;
	fputs("input n: ", stdout);
	scanf("%u", &n);
	getchar();

	for (unsigned i = 2; i <= n; ++i)
		res *= i;
	printf("result: n! = %u\n", res);

	return 0;
}
