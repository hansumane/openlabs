/*
 * Ввести с клавиатуры целое трехзначное число.
 * Найти сумму цифр введенного числа.
 */

#include <stdio.h>

int
main(void)
{
	unsigned n, sum = 0;
	fputs("input a 3-digit number: n = ", stdout);
	scanf("%u", &n);

	sum += n % 10;
	n /= 10;
	sum += n % 10;
	n /= 10;
	sum += n % 10;

	printf("result: sum = %u\n", sum);

	return 0;
}
