/*
 * Ввести с клавиатуры 10 целых положительных чисел,
 * подсчитать количество нулей.
 * Отрицательные числа игнорировать и сообщать об ошибке ввода.
 */

#include <stdio.h>

int
main(void)
{
	int array[10];
	unsigned count = 0;

	for (int i = 0; i < 10; ++i) {
		printf("input %d number: ", i + 1);
		scanf("%d", array + i);
		getchar();
		if (array[i] == 0)
			++count;
		else if (array[i] < 0) {
			fputs("wrong input! must satisfy > 0\n", stderr);
			return 1;
		}
	}

	printf("%u zeros in array\n", count);

	return 0;
}
