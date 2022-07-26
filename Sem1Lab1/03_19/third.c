/*
 * Ввести с клавиатуры 10 как положительных, так и отрицательных чисел,
 * подсчитать среднее арифметическое всех отрицательных,
 * нули игнорировать и сообщать об ошибке ввода.
 */

#include <stdio.h>

int
main(void)
{
	int array[10], sum = 0;
	unsigned count = 0;

	for (int i = 0; i < 10; ++i) {
		printf("input array[%d]: ", i);
		scanf("%d", array + i);
		getchar();
		if (array[i] < 0) {
			sum += array[i];
			++count;
		} else if (array[i] == 0) {
			fputs("wrong input! must satisfy: < 0 or > 0\n", stderr);
			return 1;
		}
	}

	if (!count)
		puts("no negative numbers!");
	else
		printf("result: %lf\n", (double)sum / count);

	return 0;
}
